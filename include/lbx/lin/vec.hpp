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

			/**
			 * @brief Returns an array with the vector's elements.
			 * @return Array with elements.
			*/
			constexpr auto arr() const
			{
				return this->getarr();
			};

			friend inline constexpr bool operator==(const crtp_type& lhs, const crtp_type& rhs)
			{
				return lhs.arr() == rhs.arr();
			};
			friend inline constexpr bool operator!=(const crtp_type& lhs, const crtp_type& rhs)
			{
				return lhs.arr() != rhs.arr();
			};

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

			template <typename _T>
			requires requires (reference a, const _T& b)
			{
				a *= b;
			}
			friend inline constexpr crtp_type operator*(const crtp_type& lhs, const _T& rhs)
			{
				auto o = lhs;
				for (auto& v : o)
				{
					v *= rhs;
				};
				return o;
			};

			template <typename _T>
			requires requires (reference a, const _T& b)
			{
				a /= b;
			}
			friend inline constexpr crtp_type operator/(const crtp_type& lhs, const _T& rhs)
			{
				auto o = lhs;
				for (auto& v : o)
				{
					v /= rhs;
				};
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

		constexpr operator vec<T, 0>() const { return vec<T, 0>(); };

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

		constexpr operator vec<T, 0>() const { return vec<T, 0>(); };
		constexpr operator vec<T, 1>() const { return vec<T, 1>(this->at(0)); };

		constexpr vec() noexcept = default;
		constexpr vec(T x, T y) noexcept :
			_LBX_LIN_VEC_ARRAY_MEMBER_NAME{ x, y }
		{};	
		constexpr explicit vec(T v) noexcept :
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
			
			struct
			{
				vec<T, 2> xy;
				T z_0_;
			};
			struct
			{
				T x_0_;
				vec<T, 2> yz;
			};

			std::array<T, 3> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};

		constexpr operator vec<T, 0>() const { return vec<T, 0>(); };
		constexpr operator vec<T, 1>() const { return vec<T, 1>(this->at(0)); };
		constexpr operator vec<T, 2>() const { return vec<T, 2>(this->at(0), this->at(1)); };

		constexpr vec() = default;
		constexpr vec(T _x, T _y, T _z) noexcept :
			_LBX_LIN_VEC_ARRAY_MEMBER_NAME{ _x, _y, _z }
		{};
		constexpr explicit vec(T v) noexcept :
			vec(v, v, v)
		{};

		constexpr explicit vec(vec<T, 1> v, T y = static_cast<T>(0), T z = static_cast<T>(0)) noexcept :
			vec(v.x, y, z)
		{};
		constexpr explicit vec(vec<T, 2> v, T z = static_cast<T>(0)) noexcept :
			vec(v.x, v.y, z)
		{};
		constexpr explicit vec(T x, vec<T, 2> v) noexcept :
			vec(x, v.x, v.y)
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

		constexpr operator vec<T, 0>() const { return vec<T, 0>(); };
		constexpr operator vec<T, 1>() const { return vec<T, 1>(this->at(0)); };
		constexpr operator vec<T, 2>() const { return vec<T, 2>(this->at(0), this->at(1)); };
		constexpr operator vec<T, 3>() const { return vec<T, 3>(this->at(0), this->at(1), this->at(2)); };

		constexpr vec() = default;
		constexpr vec(T _x, T _y, T _z, T _w) noexcept :
			_LBX_LIN_VEC_ARRAY_MEMBER_NAME{ _x, _y, _z, _w }
		{};
		constexpr explicit vec(T v) noexcept :
			vec(v, v, v, v)
		{};

		constexpr explicit vec(vec<T, 1> v, T y = static_cast<T>(0), T z = static_cast<T>(0), T w = static_cast<T>(0)) noexcept :
			vec(v.x, y, z, w)
		{};
		constexpr explicit vec(vec<T, 2> v, T z = static_cast<T>(0), T w = static_cast<T>(0)) noexcept :
			vec(v.x, v.y, z, w)
		{};
		constexpr explicit vec(vec<T, 3> v, T w = static_cast<T>(0)) noexcept :
			vec(v.x, v.y, v.z, w)
		{};
	};

	
	
	
	template <typename T>
	using vec2 = vec<T, 2>;
	template <typename T>
	using vec3 = vec<T, 3>;
	template <typename T>
	using vec4 = vec<T, 4>;
	


	template <typename T>
	vec(T, T)->vec<T, 2>;
	template <typename T>
	vec(T, T, T)->vec<T, 3>;
	template <typename T>
	vec(T, T, T, T)->vec<T, 4>;





	using uvec3 = vec<unsigned, 3>;
	using ivec3 = vec<int, 3>;
	using fvec3 = vec<float, 3>;
	using dvec3 = vec<double, 3>;

	using uvec2 = vec<unsigned, 2>;
	using ivec4 = vec<int, 4>;
	using fvec4 = vec<float, 4>;
	using dvec4 = vec<double, 4>;

	using uvec4 = vec<unsigned, 4>;
	using ivec2 = vec<int, 2>;
	using fvec2 = vec<float, 2>;
	using dvec2 = vec<double, 2>;
};

#endif // LBX_LIN_VEC_HPP