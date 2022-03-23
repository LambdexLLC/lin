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

			

		};

	};

	template <typename T>
	struct vec<T, 3>
	{
		using rep = T;
		struct
		{
			union
			{
				rep x;
				rep y;
				rep z;
			};
			std::array<rep, 3> _LBX_LIN_VEC_ARRAY_MEMBER_NAME;
		};

		
	};


};

#endif // LBX_LIN_VEC_HPP