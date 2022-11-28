set(CMAKE_CXX_COMPILER "/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/bin/g++")
set(CMAKE_CXX_COMPILER_ARG1 "")
set(CMAKE_CXX_COMPILER_ID "GNU")
set(CMAKE_CXX_COMPILER_VERSION "11.2.0")
set(CMAKE_CXX_COMPILER_VERSION_INTERNAL "")
set(CMAKE_CXX_COMPILER_WRAPPER "")
set(CMAKE_CXX_STANDARD_COMPUTED_DEFAULT "17")
set(CMAKE_CXX_EXTENSIONS_COMPUTED_DEFAULT "ON")
set(CMAKE_CXX_COMPILE_FEATURES "cxx_std_98;cxx_template_template_parameters;cxx_std_11;cxx_alias_templates;cxx_alignas;cxx_alignof;cxx_attributes;cxx_auto_type;cxx_constexpr;cxx_decltype;cxx_decltype_incomplete_return_types;cxx_default_function_template_args;cxx_defaulted_functions;cxx_defaulted_move_initializers;cxx_delegating_constructors;cxx_deleted_functions;cxx_enum_forward_declarations;cxx_explicit_conversions;cxx_extended_friend_declarations;cxx_extern_templates;cxx_final;cxx_func_identifier;cxx_generalized_initializers;cxx_inheriting_constructors;cxx_inline_namespaces;cxx_lambdas;cxx_local_type_template_args;cxx_long_long_type;cxx_noexcept;cxx_nonstatic_member_init;cxx_nullptr;cxx_override;cxx_range_for;cxx_raw_string_literals;cxx_reference_qualified_functions;cxx_right_angle_brackets;cxx_rvalue_references;cxx_sizeof_member;cxx_static_assert;cxx_strong_enums;cxx_thread_local;cxx_trailing_return_types;cxx_unicode_literals;cxx_uniform_initialization;cxx_unrestricted_unions;cxx_user_literals;cxx_variadic_macros;cxx_variadic_templates;cxx_std_14;cxx_aggregate_default_initializers;cxx_attribute_deprecated;cxx_binary_literals;cxx_contextual_conversions;cxx_decltype_auto;cxx_digit_separators;cxx_generic_lambdas;cxx_lambda_init_captures;cxx_relaxed_constexpr;cxx_return_type_deduction;cxx_variable_templates;cxx_std_17;cxx_std_20;cxx_std_23")
set(CMAKE_CXX98_COMPILE_FEATURES "cxx_std_98;cxx_template_template_parameters")
set(CMAKE_CXX11_COMPILE_FEATURES "cxx_std_11;cxx_alias_templates;cxx_alignas;cxx_alignof;cxx_attributes;cxx_auto_type;cxx_constexpr;cxx_decltype;cxx_decltype_incomplete_return_types;cxx_default_function_template_args;cxx_defaulted_functions;cxx_defaulted_move_initializers;cxx_delegating_constructors;cxx_deleted_functions;cxx_enum_forward_declarations;cxx_explicit_conversions;cxx_extended_friend_declarations;cxx_extern_templates;cxx_final;cxx_func_identifier;cxx_generalized_initializers;cxx_inheriting_constructors;cxx_inline_namespaces;cxx_lambdas;cxx_local_type_template_args;cxx_long_long_type;cxx_noexcept;cxx_nonstatic_member_init;cxx_nullptr;cxx_override;cxx_range_for;cxx_raw_string_literals;cxx_reference_qualified_functions;cxx_right_angle_brackets;cxx_rvalue_references;cxx_sizeof_member;cxx_static_assert;cxx_strong_enums;cxx_thread_local;cxx_trailing_return_types;cxx_unicode_literals;cxx_uniform_initialization;cxx_unrestricted_unions;cxx_user_literals;cxx_variadic_macros;cxx_variadic_templates")
set(CMAKE_CXX14_COMPILE_FEATURES "cxx_std_14;cxx_aggregate_default_initializers;cxx_attribute_deprecated;cxx_binary_literals;cxx_contextual_conversions;cxx_decltype_auto;cxx_digit_separators;cxx_generic_lambdas;cxx_lambda_init_captures;cxx_relaxed_constexpr;cxx_return_type_deduction;cxx_variable_templates")
set(CMAKE_CXX17_COMPILE_FEATURES "cxx_std_17")
set(CMAKE_CXX20_COMPILE_FEATURES "cxx_std_20")
set(CMAKE_CXX23_COMPILE_FEATURES "cxx_std_23")

set(CMAKE_CXX_PLATFORM_ID "Linux")
set(CMAKE_CXX_SIMULATE_ID "")
set(CMAKE_CXX_COMPILER_FRONTEND_VARIANT "")
set(CMAKE_CXX_SIMULATE_VERSION "")




set(CMAKE_AR "/cvmfs/sw.hsf.org/contrib/binutils/2.37/x86_64-centos7-gcc4.8.5-opt/e44ldsiooccrs2h2eylg3br24u74dj23/bin/ar")
set(CMAKE_CXX_COMPILER_AR "/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/bin/gcc-ar")
set(CMAKE_RANLIB "/cvmfs/sw.hsf.org/contrib/binutils/2.37/x86_64-centos7-gcc4.8.5-opt/e44ldsiooccrs2h2eylg3br24u74dj23/bin/ranlib")
set(CMAKE_CXX_COMPILER_RANLIB "/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/bin/gcc-ranlib")
set(CMAKE_LINKER "/cvmfs/sw.hsf.org/contrib/binutils/2.37/x86_64-centos7-gcc4.8.5-opt/e44ldsiooccrs2h2eylg3br24u74dj23/bin/ld")
set(CMAKE_MT "")
set(CMAKE_COMPILER_IS_GNUCXX 1)
set(CMAKE_CXX_COMPILER_LOADED 1)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_CXX_ABI_COMPILED TRUE)

set(CMAKE_CXX_COMPILER_ENV_VAR "CXX")

set(CMAKE_CXX_COMPILER_ID_RUN 1)
set(CMAKE_CXX_SOURCE_FILE_EXTENSIONS C;M;c++;cc;cpp;cxx;m;mm;mpp;CPP;ixx;cppm)
set(CMAKE_CXX_IGNORE_EXTENSIONS inl;h;hpp;HPP;H;o;O;obj;OBJ;def;DEF;rc;RC)

foreach (lang C OBJC OBJCXX)
  if (CMAKE_${lang}_COMPILER_ID_RUN)
    foreach(extension IN LISTS CMAKE_${lang}_SOURCE_FILE_EXTENSIONS)
      list(REMOVE_ITEM CMAKE_CXX_SOURCE_FILE_EXTENSIONS ${extension})
    endforeach()
  endif()
endforeach()

set(CMAKE_CXX_LINKER_PREFERENCE 30)
set(CMAKE_CXX_LINKER_PREFERENCE_PROPAGATES 1)

# Save compiler ABI information.
set(CMAKE_CXX_SIZEOF_DATA_PTR "8")
set(CMAKE_CXX_COMPILER_ABI "ELF")
set(CMAKE_CXX_BYTE_ORDER "LITTLE_ENDIAN")
set(CMAKE_CXX_LIBRARY_ARCHITECTURE "")

if(CMAKE_CXX_SIZEOF_DATA_PTR)
  set(CMAKE_SIZEOF_VOID_P "${CMAKE_CXX_SIZEOF_DATA_PTR}")
endif()

if(CMAKE_CXX_COMPILER_ABI)
  set(CMAKE_INTERNAL_PLATFORM_ABI "${CMAKE_CXX_COMPILER_ABI}")
endif()

if(CMAKE_CXX_LIBRARY_ARCHITECTURE)
  set(CMAKE_LIBRARY_ARCHITECTURE "")
endif()

set(CMAKE_CXX_CL_SHOWINCLUDES_PREFIX "")
if(CMAKE_CXX_CL_SHOWINCLUDES_PREFIX)
  set(CMAKE_CL_SHOWINCLUDES_PREFIX "${CMAKE_CXX_CL_SHOWINCLUDES_PREFIX}")
endif()





set(CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES "/cvmfs/sw.hsf.org/spackages5/physsim/0.4.1/x86_64-centos7-gcc11.2.0-opt/3misx/include/physsim;/cvmfs/sw.hsf.org/spackages5/kaldet/1.14.1/x86_64-centos7-gcc11.2.0-opt/4cvoj/include/kaldet;/cvmfs/sw.hsf.org/spackages5/kaltest/2.5/x86_64-centos7-gcc11.2.0-opt/drqab/include/kaltest;/cvmfs/sw.hsf.org/spackages5/eigen/3.4.0/x86_64-centos7-gcc11.2.0-opt/wop4u/include/eigen3;/cvmfs/sw.hsf.org/spackages5/lcio/2.17/x86_64-centos7-gcc11.2.0-opt/mpa5b;/cvmfs/sw.hsf.org/spackages5/python/3.9.10/x86_64-centos7-gcc11.2.0-opt/7j5vq/include/python3.9;/cvmfs/sw.hsf.org/contrib/gcc/8.3.0/x86_64-centos7-gcc4.8.5-opt/3tor3brwrrwwjs5jhvwrb5plauumwozz/include;/cvmfs/sw.hsf.org/contrib/mpc/1.1.0/x86_64-centos7-gcc4.8.5-opt/t7q4u2qxpzjyba4jd5vxb6rnr65rhtld/include;/cvmfs/sw.hsf.org/contrib/mpfr/3.1.6/x86_64-centos7-gcc4.8.5-opt/ij7i5ewhwicuz6btw3uzap7v4ricroet/include;/cvmfs/sw.hsf.org/contrib/gmp/6.2.1/x86_64-centos7-gcc4.8.5-opt/rw2ikt3b5d6jl6w7h6v2o2gluhtmr6di/include;/cvmfs/sw.hsf.org/contrib/binutils/2.37/x86_64-centos7-gcc4.8.5-opt/e44ldsiooccrs2h2eylg3br24u74dj23/include;/cvmfs/sw.hsf.org/contrib/gettext/0.21/x86_64-centos7-gcc4.8.5-opt/sjch4vbkwmt2yul7drb3kw4p4cbgxa36/include;/cvmfs/sw.hsf.org/contrib/ncurses/6.2/x86_64-centos7-gcc4.8.5-opt/pjjehj2mzxqzfdqqia3fcgh6axembubq/include;/cvmfs/sw.hsf.org/contrib/libxml2/2.9.12/x86_64-centos7-gcc4.8.5-opt/n6jpcqxfdqbcepfb7dx7jgw6brcqck7w/include;/cvmfs/sw.hsf.org/contrib/zlib/1.2.11/x86_64-centos7-gcc4.8.5-opt/y7ojc3yjt2zfof5ntgwkerhw3eojtyed/include;/cvmfs/sw.hsf.org/contrib/xz/5.2.5/x86_64-centos7-gcc4.8.5-opt/gvi5itc7jlpyqfm6dbn7cmwftjpn75zr/include;/cvmfs/sw.hsf.org/contrib/libiconv/1.16/x86_64-centos7-gcc4.8.5-opt/ycvsaekan5tlzueyp4ylpxnohrws7jlc/include;/cvmfs/sw.hsf.org/contrib/bzip2/1.0.8/x86_64-centos7-gcc4.8.5-opt/ceo6esx3tynrmqufzjhorensrssplo3m/include;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/include/c++/11.2.0;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/include/c++/11.2.0/x86_64-pc-linux-gnu;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/include/c++/11.2.0/backward;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/lib/gcc/x86_64-pc-linux-gnu/11.2.0/include;/usr/local/include;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/include;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/lib/gcc/x86_64-pc-linux-gnu/11.2.0/include-fixed;/usr/include")
set(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "stdc++;m;gcc_s;gcc;c;gcc_s;gcc")
set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES "/cvmfs/sw.hsf.org/contrib/gcc/8.3.0/x86_64-centos7-gcc4.8.5-opt/3tor3brwrrwwjs5jhvwrb5plauumwozz/lib64;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/lib/gcc/x86_64-pc-linux-gnu/11.2.0;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/lib64;/lib64;/usr/lib64;/cvmfs/sw.hsf.org/spackages5/libzmq/4.3.4/x86_64-centos7-gcc11.2.0-opt/gmocg/lib;/cvmfs/sw.hsf.org/contrib/gcc/8.3.0/x86_64-centos7-gcc4.8.5-opt/3tor3brwrrwwjs5jhvwrb5plauumwozz/lib;/cvmfs/sw.hsf.org/contrib/mpc/1.1.0/x86_64-centos7-gcc4.8.5-opt/t7q4u2qxpzjyba4jd5vxb6rnr65rhtld/lib;/cvmfs/sw.hsf.org/contrib/mpfr/3.1.6/x86_64-centos7-gcc4.8.5-opt/ij7i5ewhwicuz6btw3uzap7v4ricroet/lib;/cvmfs/sw.hsf.org/contrib/gmp/6.2.1/x86_64-centos7-gcc4.8.5-opt/rw2ikt3b5d6jl6w7h6v2o2gluhtmr6di/lib;/cvmfs/sw.hsf.org/contrib/binutils/2.37/x86_64-centos7-gcc4.8.5-opt/e44ldsiooccrs2h2eylg3br24u74dj23/lib;/cvmfs/sw.hsf.org/contrib/gettext/0.21/x86_64-centos7-gcc4.8.5-opt/sjch4vbkwmt2yul7drb3kw4p4cbgxa36/lib;/cvmfs/sw.hsf.org/contrib/ncurses/6.2/x86_64-centos7-gcc4.8.5-opt/pjjehj2mzxqzfdqqia3fcgh6axembubq/lib;/cvmfs/sw.hsf.org/contrib/libxml2/2.9.12/x86_64-centos7-gcc4.8.5-opt/n6jpcqxfdqbcepfb7dx7jgw6brcqck7w/lib;/cvmfs/sw.hsf.org/contrib/zlib/1.2.11/x86_64-centos7-gcc4.8.5-opt/y7ojc3yjt2zfof5ntgwkerhw3eojtyed/lib;/cvmfs/sw.hsf.org/contrib/xz/5.2.5/x86_64-centos7-gcc4.8.5-opt/gvi5itc7jlpyqfm6dbn7cmwftjpn75zr/lib;/cvmfs/sw.hsf.org/contrib/libiconv/1.16/x86_64-centos7-gcc4.8.5-opt/ycvsaekan5tlzueyp4ylpxnohrws7jlc/lib;/cvmfs/sw.hsf.org/contrib/bzip2/1.0.8/x86_64-centos7-gcc4.8.5-opt/ceo6esx3tynrmqufzjhorensrssplo3m/lib;/cvmfs/sw.hsf.org/contrib/gcc/11.2.0/x86_64-centos7-gcc8.3.0-opt/4omkc/lib")
set(CMAKE_CXX_IMPLICIT_LINK_FRAMEWORK_DIRECTORIES "")
