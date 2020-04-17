#pragma once
#include "xsFunctionName.h"
#include "xsStringFilter.h"

namespace xsUtil
{
    template<typename T>
    struct type_tag
    {
        constexpr type_tag() = default;
        using type = T;
    };

    namespace Impl
    {
        template<typename T>
        struct nameof_impl
        {
            static constexpr xsDS::CString apply()
            {
                return filter_typename_prefix(xsUtil::type<T>().pad(XS_FUNCTIONNAME_LEFT, XS_FUNCTIONNAME_RIGTH));
            }
        };
    }


    template<typename T>
    constexpr xsDS::CString xs_nameof(xsUtil::type_tag<T>)
    {
        return xsUtil::Impl::nameof_impl<T>::apply();
    }

    template<typename T>
    constexpr xsDS::CString nameof()
    {
        return xs_nameof(xsUtil::type_tag<T>());
    }
}

