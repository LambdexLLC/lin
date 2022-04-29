#pragma once
#ifndef LBX_LIN_MAT_HPP
#define LBX_LIN_MAT_HPP

#include <lbx/lin/vec.hpp>
#include <lbx/lin/vector_math.hpp>

#include <lbx/lin/detail/type.hpp>
#include <lbx/lin/detail/assert.hpp>

#include <array>

namespace lbx
{
	namespace impl
	{
		template <typename T, usize Columns, usize Rows>
		struct mat_base
		{
		public:

			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;
			using const_pointer = const value_type*;
			using const_reference = const value_type&;

			using size_type = usize;
			using pos_type = vec2<size_type>;


			constexpr size_type pos_to_index(pos_type _pos) const
			{
				_LBX_LIN_ASSERT(_pos.x < Columns);
				_LBX_LIN_ASSERT(_pos.y < Rows);
				return (_pos.x * Columns) + _pos.y;
			};
			constexpr pos_type index_to_pos(size_type _index) const
			{
				vec2<size_type> _pos;
				_pos.x = _index / Columns;
				_pos.y = _index - (_pos.x * Columns);
				return _pos;
			};

			constexpr reference at(size_type _index)
			{
				return this->data_.at(_index);
			};
			constexpr const_reference at(size_type _index) const
			{
				return this->data_.at(_index);
			};

			constexpr reference at(pos_type _pos)
			{
				const auto _index = this->pos_to_index(_pos);
				return this->at(_index);
			};
			constexpr const_reference at(pos_type _pos) const
			{
				const auto _index = this->pos_to_index(_pos);
				return this->at(_index);
			};

			constexpr reference operator[](size_type _index)
			{
				return this->at(_index);
			};
			constexpr const_reference operator[](size_type _index) const
			{
				return this->at(_index);
			};

			constexpr reference operator[](pos_type _pos)
			{
				return this->at(_pos);
			};
			constexpr const_reference operator[](pos_type _pos) const
			{
				return this->at(_pos);
			};

			constexpr pointer data() noexcept { return this->data_.data(); };
			constexpr const_pointer data() const noexcept { return this->data_.data(); };

			constexpr size_type size() const noexcept { return this->data_.size(); };
			constexpr size_type size_bytes() const noexcept { return this->size() * sizeof(value_type); };



			constexpr mat_base() = default;

		private:
			std::array<value_type, Rows * Columns> data_;
		};
	};

	template <typename T, usize C, usize R>
	struct mat : public impl::mat_base<T, C, R>
	{
	private:
		using parent_type = impl::mat_base<T, C, R>;
	public:
		using parent_type::parent_type;
	};

	template <typename T, usize CR>
	struct mat<T, CR, CR> : public impl::mat_base<T, CR, CR>
	{
	private:
		using parent_type = impl::mat_base<T, CR, CR>;
	public:
		using parent_type::parent_type;

		/**
		 * @brief Initializes the matrix as an identity matrix with a given value.
		 * @param _identityValue The value to set the diagonal positions to.
		*/
		constexpr mat(const T& _identityValue) :
			parent_type{}
		{
			for (typename parent_type::size_type n = 0; n != CR; ++n)
			{
				this->at(typename parent_type::pos_type(n)) = _identityValue;
			};
		};
	};


	template <typename T>
	using mat4 = mat<T, 4, 4>;
	using fmat4 = mat4<float>;
	using dmat4 = mat4<double>;

};

namespace lbx
{
	template <typename T>
	inline mat4<T> scale(mat4<T> _mat, const vec3<T>& _scale)
	{
		_mat.at({ 0, 0 }) *= _scale[0];
		_mat.at({ 1, 1 }) *= _scale[1];
		_mat.at({ 2, 2 }) *= _scale[2];
		return _mat;
	};
	template <typename T>
	inline mat4<T> translate(mat4<T> _mat, const vec3<T>& _delta)
	{
		_mat.at({ 3, 0 }) += _delta[0];
		_mat.at({ 3, 1 }) += _delta[1];
		_mat.at({ 3, 2 }) += _delta[2];
		return _mat;
	};
	
	
	
	
	template<typename T>
	inline mat4<T> ortho(T _left, T _right, T _bottom, T _top)
	{
		mat4<T> o(static_cast<T>(1));
		o[{ 0, 0 }] = static_cast<T>(2) / (_right - _left);
		o[{ 1, 1 }] = static_cast<T>(2) / (_top - _bottom);
		o[{ 2, 2 }] = -static_cast<T>(1);
		o[{ 3, 0 }] = -(_right + _left) / (_right - _left);
		o[{ 3, 1 }] = -(_top + _bottom) / (_top - _bottom);
		return o;
	};



	template<typename T>
	inline mat4<T> look_at(const vec3<T>& _eye, const vec3<T>& _center, const vec3<T>& _up)
	{
		const vec3<T> f(normalize(_center - _eye));
		const vec3<T> s(normalize(cross(f, _up)));
		const vec3<T> u(cross(s, f));

		mat4<T> Result(1);
		Result[{ 0, 0 }] = s.x;
		Result[{ 1, 0 }] = s.y;
		Result[{ 2, 0 }] = s.z;
		Result[{ 0, 1 }] = u.x;
		Result[{ 1, 1 }] = u.y;
		Result[{ 2, 1 }] = u.z;
		Result[{ 0, 2 }] = -f.x;
		Result[{ 1, 2 }] = -f.y;
		Result[{ 2, 2 }] = -f.z;
		Result[{ 3, 0 }] = -dot(s, _eye);
		Result[{ 3, 1 }] = -dot(u, _eye);
		Result[{ 3, 2 }] = dot(f, _eye);
		return Result;
	};

	template<typename T>
	inline mat4<T> perspective(lbx::radians fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));
		
		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat4<T> Result(static_cast<T>(0));
		Result[{ 0, 0 }] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[{ 1, 1 }] = static_cast<T>(1) / (tanHalfFovy);
		Result[{ 2, 2 }] = -(zFar + zNear) / (zFar - zNear);
		Result[{ 2, 3 }] = -static_cast<T>(1);
		Result[{ 3, 2 }] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

};


#endif // LBX_LIN_MAT_HPP