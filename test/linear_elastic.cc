#include "catch.hpp"

#include "constitutive/configurations.h"
#include "constitutive/mech/linear_elastic.h"

using namespace constitutive;

TEST_CASE("linear elastic", "[mech]") {
  LinearElastic<configs::DealII> material{LambdaMu(100., 60.)};
}