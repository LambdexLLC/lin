#pragma once
#ifndef LBX_LIN_MAT_HPP
#define LBX_LIN_MAT_HPP

/** @file */

#include <lbx/lin/vec.hpp>
#include <lbx/lin/vector_math.hpp>

#include <lbx/lin/detail/type.hpp>
#include <lbx/lin/detail/assert.hpp>

#include <array>
#include <initializer_list>

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

			using column_vec = vec<value_type, Rows>;

			constexpr auto begin() { return this->data_.begin(); };
			constexpr auto begin() const { return this->data_.cbegin(); };
			constexpr auto cbegin() const { return this->data_.cbegin(); };

			constexpr auto end() { return this->data_.end(); };
			constexpr auto end() const { return this->data_.cend(); };
			constexpr auto cend() const { return this->data_.cend(); };



			constexpr size_type pos_to_index(pos_type _pos) const
			{
				_LBX_LIN_ASSERT(_pos.x < Columns);
				_LBX_LIN_ASSERT(_pos.y < Rows);
				return (_pos.x * Columns) + _pos.y;
			};

			template <std::integral _T>
			constexpr size_type pos_to_index(vec2<_T> _pos) const
			{
				_LBX_LIN_ASSERT(_pos.x < Columns);
				_LBX_LIN_ASSERT(_pos.y < Rows);
				return static_cast<size_type>((_pos.x * Columns) + _pos.y);
			};


			constexpr pos_type index_to_pos(size_type _index) const
			{
				vec2<size_type> _pos;
				_pos.x = _index / Columns;
				_pos.y = _index - (_pos.x * Columns);
				return _pos;
			};



			constexpr column_vec& at(size_type _index)
			{
				return this->data_.at(_index);
			};
			constexpr const column_vec& at(size_type _index) const
			{
				return this->data_.at(_index);
			};

			constexpr reference at(pos_type _pos)
			{
				return this->data_[_pos.x][_pos.y];
			};
			constexpr const_reference at(pos_type _pos) const
			{
				return this->data_[_pos.x][_pos.y];
			};

			template <std::integral _T>
			constexpr reference at(vec2<_T> _pos)
			{
				return this->data_[_pos.x][_pos.y];
			};
			template <std::integral _T>
			constexpr const_reference at(vec2<_T> _pos) const
			{
				return this->data_[_pos.x][_pos.y];
			};



			constexpr vec<T, Columns> row(size_type n) const
			{
				auto o = vec<T, Columns>();
				size_type vn = 0;
				for (auto& v : o)
				{
					v = this->at({ vn++, n });
				};
				return o;
			};
			constexpr vec<T, Rows> column(size_type n) const
			{
				auto o = vec<T, Rows>();
				size_type vn = 0;
				for (auto& v : o)
				{
					v = this->at({ n, vn++ });
				};
				return o;
			};



			constexpr column_vec& operator[](size_type v)
			{
				return this->at(v);
			};
			constexpr const column_vec& operator[](size_type v) const
			{
				return this->at(v);
			};

			constexpr reference operator[](pos_type _pos)
			{
				return this->at(_pos);
			};
			constexpr const_reference operator[](pos_type _pos) const
			{
				return this->at(_pos);
			};

			template <std::integral _T>
			constexpr reference operator[](vec2<_T> _pos)
			{
				return this->at(_pos);
			};
			template <std::integral _T>
			constexpr const_reference operator[](vec2<_T> _pos) const
			{
				return this->at(_pos);
			};



			constexpr pointer data() noexcept { return this->data_.front().data(); };
			constexpr const_pointer data() const noexcept { return this->data_.front().data(); };

			constexpr size_type nrows() const noexcept
			{
				return Rows;
			};
			constexpr size_type ncolumns() const noexcept
			{
				return Columns;
			};

			constexpr size_type size() const noexcept
			{
				return this->nrows() * this->ncolumns();
			};
			constexpr size_type size_bytes() const noexcept
			{
				return this->size() * sizeof(value_type);
			};

			constexpr void set_row(size_type n, vec<T, Columns> _vec)
			{
				size_type vn = 0;
				for (auto& v : _vec)
				{
					this->at({ vn++, n }) = v;
				};
			};
			constexpr void set_column(size_type n, vec<T, Rows> _vec)
			{
				size_type vn = 0;
				for (auto& v : _vec)
				{
					this->at({ n, vn++ }) = v;
				};
			};



			constexpr mat_base() = default;

			constexpr mat_base(std::initializer_list<column_vec> _columns) :
				data_()
			{
				size_type n = 0;
				for (auto& v : _columns)
				{
					auto p = this->at(n).data();
					std::copy(v.begin(), v.end(), p);
				};
			};

		private:
			std::array<column_vec, Columns> data_;
		};

		template <typename MatT, typename T, size_t C, size_t R>
		struct mat_interface : public mat_base<T, C, R>
		{
			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;
			using const_pointer = const value_type*;
			using const_reference = const value_type&;
			using size_type = usize;

			constexpr friend inline MatT operator+(const MatT& lhs, const MatT& rhs)
			{
				auto o = MatT();
				for (size_type n = 0; n != lhs.size(); ++n)
				{
					o[n] = lhs[n] + rhs[n];
				};
				return o;
			};

			constexpr friend inline MatT operator*(const MatT& lhs, const_reference rhs)
			{
				auto o = MatT(lhs);
				for (auto& v : o) { v *= rhs; };
				return o;
			};
			constexpr friend inline MatT operator*(const_reference lhs, const MatT& rhs)
			{
				auto o = MatT(rhs);
				for (auto& v : o) { v *= lhs; };
				return o;
			};

			constexpr friend inline MatT operator/(const MatT& lhs, const_reference rhs)
			{
				auto o = MatT(lhs);
				for (auto& v : o) { v /= rhs; };
				return o;
			};
			constexpr friend inline MatT operator/(const_reference lhs, const MatT& rhs)
			{
				auto o = MatT(rhs);
				for (auto& v : o) { v /= lhs; };
				return o;
			};

			using mat_base<T, C, R>::mat_base;
		};

	};


	template <typename T, usize C, usize R>
	struct mat : public impl::mat_interface<mat<T, C, R>, T, C, R>
	{
	private:
		using parent_type = impl::mat_interface<mat<T, C, R>, T, C, R>;
	public:
		using parent_type::parent_type;
	};

	template <typename T, usize CR>
	struct mat<T, CR, CR> : public impl::mat_interface<mat<T, CR, CR>, T, CR, CR>
	{
	private:
		using parent_type = impl::mat_interface<mat<T, CR, CR>, T, CR, CR>;
	public:
		using parent_type::parent_type;

		/**
		 * @brief Initializes the matrix as an identity matrix with a given value.
		 * @param _identityValue The value to set the diagonal positions to.
		*/
		constexpr mat(const T& _identityValue) :
			parent_type{}
		{
			using size_type = typename parent_type::size_type;
			for (size_type cr = 0; cr != CR; ++cr)
			{
				(*this)[cr][cr] = _identityValue;
			};
		};
	};

	template <typename T, size_t N>
	constexpr T sum(const vec<T, N>& _vec)
	{
		auto o = T();
		for (auto& v : _vec) { o += v; };
		return o;
	};

	template <typename T, size_t C, size_t R>
	constexpr vec<T, R> operator*(const mat<T, C, R>& lhs, const vec<T, R>& rhs)
	{
		auto o = vec<T, R>();
		for (size_t n = 0; n != R; ++n)
		{
			const auto pv = sum(lhs.row(n) * rhs);
			o[n] = pv;
		};
		return o;
	};

	template <typename T, size_t C, size_t R>
	constexpr vec<T, R> operator*(const vec<T, R>& lhs, const mat<T, C, R>& rhs)
	{
		return rhs * lhs;
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
	
	template <typename T, size_t Rows, size_t Columns>
	inline mat<T, Columns, Rows> transpose(const mat<T, Rows, Columns>& _mat)
	{
		auto o = mat<T, Columns, Rows>();
		for (size_t r = 0; r != Rows; ++r)
		{
			for (size_t c = 0; c != Columns; ++c)
			{
				o[vec2{ c, r }] = _mat[vec2{ r, c }];
			};
		};
		return o;
	};

	template <typename T>
	inline mat4<T> from_rows(vec4<T> a, vec4<T> b, vec4<T> c, vec4<T> d)
	{
		return transpose(mat4<T>{ a, b, c, d });
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