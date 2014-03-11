add_library(MathFunctions mysqrt.cpp MathFunctions.hpp)

install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.hpp DESTINATION include)
