#pragma once

#include <utility>
#include <type_traits>


namespace lbx
{
	namespace impl
	{
		struct basic_unit_tag {};
	};

	template <typename T, typename Enable = void>
	struct is_unit : std::integral_constant<bool, false> {};
	template <typename T>
	struct is_unit<T, std::enable_if_t<std::is_base_of<impl::basic_unit_tag, T>::value>>
		: std::integral_constant<bool, true> {};

	template <typename T>
	constexpr inline bool is_unit_v = is_unit<T>::value;



	template <typename T, typename TagT>
	struct basic_unit;

	template <typename FromT, typename ToT>
	struct unit_cast_t;

	template <typename FromT, typename ToT, typename Enable = void>
	struct has_implicit_unit_cast_t : std::false_type {};
	template <typename FromT, typename ToT>
	struct has_implicit_unit_cast_t<FromT, ToT, std::void_t<
		decltype(unit_cast_t<FromT, ToT>::implicit_cast(std::declval<const FromT&>()))
	>> : std::true_type {};



	template <typename T, typename TagT>
	struct basic_unit : public impl::basic_unit_tag
	{
	public:
		using rep = T;
		using tag = TagT;

		constexpr rep count() const noexcept { return this->rep_; };
		constexpr explicit operator rep() const noexcept { return this->count(); };

		constexpr basic_unit operator-() const
		{
			return basic_unit(this->count());
		};

		constexpr basic_unit& operator+=(const basic_unit& rhs)
		{
			auto& lhs = *this;
			lhs.rep_ += rhs.count();
			return lhs;
		};
		constexpr basic_unit operator+(const basic_unit& rhs) const
		{
			auto& lhs = *this;
			auto o = lhs;
			o.rep_ += rhs;
			return o;
		};
		constexpr basic_unit& operator-=(const basic_unit& rhs)
		{
			auto& lhs = *this;
			lhs.rep_ -= rhs.count();
			return lhs;
		};
		constexpr basic_unit operator-(const basic_unit& rhs) const
		{
			auto& lhs = *this;
			auto o = lhs;
			o.rep_ -= rhs;
			return o;
		};

		constexpr bool operator==(const basic_unit& rhs) const noexcept = default;
		constexpr bool operator!=(const basic_unit& rhs) const noexcept = default;

		constexpr bool operator>(const basic_unit& rhs) const noexcept
		{
			auto& lhs = *this;
			return lhs.count() > rhs.count();
		};
		constexpr bool operator<(const basic_unit& rhs) const noexcept
		{
			auto& lhs = *this;
			return lhs.count() < rhs.count();
		};
		constexpr bool operator>=(const basic_unit& rhs) const noexcept
		{
			auto& lhs = *this;
			return lhs.count() >= rhs.count();
		};
		constexpr bool operator<=(const basic_unit& rhs) const noexcept
		{
			auto& lhs = *this;
			return lhs.count() <= rhs.count();
		};

		constexpr basic_unit() = default;
		constexpr explicit basic_unit(const rep& _value) noexcept :
			rep_(_value)
		{};

		template <typename _FromT, typename = std::enable_if_t<has_implicit_unit_cast_t<_FromT, basic_unit>::value>>
		constexpr basic_unit(const _FromT& u) :
			basic_unit(unit_cast_t<_FromT, basic_unit>::implicit_cast(u))
		{};

	private:
		rep rep_;
	};

};


