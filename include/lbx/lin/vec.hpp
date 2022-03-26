#pragma once
#ifndef LBX_LIN_VEC_HPP
#define LBX_LIN_VEC_HPP

/** @file */

#include <array>
#include <cstdint>


#define _LBX_LIN_VEC_ARRAY_MEMBER_NAME arr_


namespace lbx
{
	template <typename T, size_t N>
	struct vec;

	namespace impl
	{
		template <typename VecT, typename T>
		struct vec_interface
		{
		private:
			using crtp_type = VecT;
			constexpr auto& crtp() noexcept { return *static_cast<crtp_type*>(this); };
			constexpr auto& crtp() const noexcept { return *static_cast<const crtp_type*>(this); };
			constexpr auto& getarr() noexcept { return this->crtp()._LBX_LIN_VEC_ARRAY_MEMBER_NAME; };
			constexpr auto& getarr() const noexcept { return this->crtp()._LBX_LIN_VEC_ARRAY_MEMBER_NAME; };
		public:
			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;
			using const_pointer = const value_type*;
			using const_reference = const value_type&;
			using size_type = size_t;

			constexpr auto begin() noexcept { return this->getarr().begin(); };
			constexpr auto begin() const noexcept { return this->getarr().cbegin(); };
			constexpr auto cbegin() const noexcept { return this->getarr().cbegin(); };

			constexpr auto end() noexcept { return this->getarr().end(); };
			constexpr auto end() const noexcept { return this->getarr().cend(); };
			constexpr auto cend() const noexcept { return this->getarr().cend(); };


			constexpr size_type size() const noexcept { return this->getarr().size(); };

			constexpr pointer data() noexcept { return this->getarr().data(); };
			constexpr const_pointer data() const noexcept { return this->getarr().data(); };

			constexpr reference at(size_type n) noexcept { return this->getarr().at(n); };
			constexpr const_reference at(size_type n) const noexcept { return this->getarr().at(n); };

			constexpr reference operator[](size_type n) noexcept { return this->at(n); };
			constexpr const_reference operator[](size_type n) const noexcept { return this->at(n); };

			friend inline constexpr crtp_type& operator+=(crtp_type& lhs, const crtp_type& rhs)
			{
				for (size_type n = 0; n != lhs.size(); ++n)
				{
					lhs[n] += rhs[n];
				};
				return lhs;
			};
			friend inline constexpr crtp_type& operator-=(crtp_type& lhs, const crtp_type& rhs)
			{
				for (size_type n = 0; n != lhs.size(); ++n)
				{
					lhs[n] -= rhs[n];
				};
				return lhs;
			};
			friend inline constexpr crtp_type& operator*=(crtp_type& lhs, const crtp_type& rhs)
			{
				for (size_type n = 0; n != lhs.size(); ++n)
				{
					lhs[n] *= rhs[n];
				};
				return lhs;
			};
			friend inline constexpr crtp_type& operator/=(crtp_type& lhs, const crtp_type& rhs)
			{
				for (size_type n = 0; n != lhs.size(); ++n)
				{
					lhs[n] /= rhs[n];
				};
				return lhs;
			};
			
			friend inline constexpr crtp_type operator+(const crtp_type& lhs, const crtp_type& rhs)
			{
				auto o = lhs;
				o += rhs;
				return o;
			};
			friend inline constexpr crtp_type operator-(const crtp_type& lhs, const crtp_type& rhs)
			{
				auto o = lhs;
				o -= rhs;
				return o;
			};
			friend inline constexpr crtp_type operator*(const crtp_type& lhs, const crtp_type& rhs)
			{
				auto o = lhs;
				o *= rhs;
				return o;
			};
			friend inline constexpr crtp_type operator/(const crtp_type& lhs, const crtp_type& rhs)
			{
				auto o = lhs;
				o /= rhs;
				return o;
			};

			friend inline constexpr crtp_type& operator+=(crtp_type& lhs, const_reference rhs)
			{
				for (auto& v : lhs)
				{
					v += rhs;
				};
				return lhs;
			};
			friend inline constexpr crtp_type& operator-=(crtp_type& lhs, const_reference rhs)
			{
				for (auto& v : lhs)
				{
					v -= rhs;
				};
				return lhs;
			};
			friend inline constexpr crtp_type& operator*=(crtp_type& lhs, const_reference rhs)
			{
				for (auto& v : lhs)
				{
					v *= rhs;
				};
				return lhs;
			};
			friend inline constexpr crtp_type& operator/=(crtp_type& lhs, const_reference rhs)
			{
				for (auto& v : lhs)
				{
					v /= rhs;
				};
				return lhs;
			};

			friend inline constexpr crtp_type operator+(const crtp_type& lhs, const_reference rhs)
			{
				auto o = lhs;
				o += rhs;
				return o;
			};
			friend inline constexpr crtp_type operator-(const crtp_type& lhs, const_reference rhs)
			{
				auto o = lhs;
				o -= rhs;
				return o;
			};
			friend inline constexpr crtp_type operator*(const crtp_type& lhs, const_reference rhs)
			{
				auto o = lhs;
				o *= rhs;
				return o;
			};
			friend inline constexpr crtp_type operator/(const crtp_type& lhs, const_reference rhs)
			{
				auto o = lhs;
				o /= rhs;
				return o;
			};

			friend inline constexpr crtp_type operator-(const crtp_type& rhs)
			{
				auto o = rhs;
				for (auto& v : o)
				{
					v = -v;
				};
				return o;
			};


			constexpr vec_interface() noexcept = default;
		};
	};

	template <typename T>
	struct vec<T, 0> : public impl::vec_interface<vec<T, 0>, T>
	{
		std::array<T, 0> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;

		constexpr vec() noexcept = default;
	};

	template <typename T>
	struct vec<T, 1> : public impl::vec_interface<vec<T, 1>, T>
	{
		union
		{
			struct
			{
				T x;
			};
			std::array<T, 1> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};

		constexpr vec() noexcept = default;
		constexpr vec(T x) noexcept :
			_LBX_LIN_VEC_ARRAY_MEMBER_NAME{ x }
		{};
	};

	template <typename T>
	struct vec<T, 2> : public impl::vec_interface<vec<T, 2>, T>
	{
		union
		{
			struct
			{
				T x;
				T y;
			};
			std::array<T, 2> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};

		constexpr vec() noexcept = default;
		constexpr vec(T x, T y) noexcept :
			_LBX_LIN_VEC_ARRAY_MEMBER_NAME{ x, y }
		{};	
		constexpr vec(T v) noexcept :
			vec(v, v)
		{};
	};

	template <typename T>
	struct vec<T, 3> : public impl::vec_interface<vec<T, 3>, T>
	{
		union
		{
			struct
			{
				T x;
				T y;
				T z;
			};
			std::array<T, 3> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};

		constexpr vec() = default;
		constexpr vec(T _x, T _y, T _z) noexcept :
			_LBX_LIN_VEC_ARRAY_MEMBER_NAME{ _x, _y, _z }
		{};
		constexpr vec(T v) noexcept :
			vec(v, v, v)
		{};
	};

	template <typename T>
	struct vec<T, 4> : public impl::vec_interface<vec<T, 4>, T>
	{
		union
		{
			struct
			{
				T x;
				T y;
				T z;
				T w;
			};
			std::array<T, 4> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};

		constexpr vec() = default;
		constexpr vec(T _x, T _y, T _z, T _w) noexcept :
			_LBX_LIN_VEC_ARRAY_MEMBER_NAME{ _x, _y, _z, _w }
		{};
		constexpr vec(T v) noexcept :
			vec(v, v, v, v)
		{};
	};

	
	
	
	template <typename T>
	using vec2 = vec<T, 2>;
	template <typename T>
	using vec4 = vec<T, 4>;


	using uvec2 = vec<unsigned, 2>;
	using uvec4 = vec<unsigned, 4>;

	using ivec2 = vec<int, 2>;
	using ivec4 = vec<int, 4>;

	using fvec2 = vec<float, 2>;
	using fvec4 = vec<float, 4>;

	using dvec2 = vec<double, 2>;
	using dvec4 = vec<double, 4>;

	
};

#endif // LBX_LIN_VEC_HPP