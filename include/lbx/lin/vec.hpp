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
			constexpr auto& crtp() const noexcept { return *static_cast<crtp_type*>(this); };
			constexpr auto& getarr() noexcept { return this->crtp()._LBX_LIN_VEC_ARRAY_MEMBER_NAME; };
			constexpr auto& getarr() const noexcept { return this->crtp()._LBX_LIN_VEC_ARRAY_MEMBER_NAME; };
		public:
			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;
			using const_pointer = const value_type*;
			using const_reference = const value_type&;
			using size_type = size_t;
			constexpr size_type size() const noexcept { this->getarr().size(); };
			constexpr pointer data() noexcept { this->getarr().data(); };
			constexpr const_pointer data() const noexcept { this->getarr().data(); };
			constexpr reference at(size_type n) noexcept { return this->getarr().at(n); };
			constexpr const_reference at(size_type n) const noexcept { return this->getarr().at(n); };
			constexpr reference operator[](size_type n) noexcept { return this->at(n); };
			constexpr const_reference operator[](size_type n) const noexcept { return this->at(n); };
			constexpr auto begin() noexcept { return this->getarr().begin(); };
			constexpr auto begin() const noexcept { return this->getarr().cbegin(); };
			constexpr auto cbegin() const noexcept { return this->getarr().cbegin(); };
			constexpr auto end() noexcept { return this->getarr().end(); };
			constexpr auto end() const noexcept { return this->getarr().cend(); };
			constexpr auto cend() const noexcept { return this->getarr().cend(); };
		};
	};

	template <typename T>
	struct vec<T, 0> : public impl::vec_interface<vec<T, 0>, T>
	{
		std::array<T, 0> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
	};

	template <typename T>
	struct vec<T, 1> : public impl::vec_interface<vec<T, 1>, T>
	{
		struct
		{
			union
			{
				T x;
			};
			std::array<T, 1> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};
	};

	template <typename T>
	struct vec<T, 2> : public impl::vec_interface<vec<T, 2>, T>
	{
		struct
		{
			union
			{
				T x;
				T y;
			};
			std::array<T, 2> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};
	};

	template <typename T>
	struct vec<T, 3> : public impl::vec_interface<vec<T, 3>, T>
	{
		struct
		{
			union
			{
				T x;
				T y;
				T z;
			};
			std::array<T, 3> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};
	};

	template <typename T>
	struct vec<T, 4> : public impl::vec_interface<vec<T, 4>, T>
	{
		struct
		{
			union
			{
				T x;
				T y;
				T z;
				T w;
			};
			std::array<T, 4> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};
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