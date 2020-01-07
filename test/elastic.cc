#include "catch.hpp"

#include "constitutive/mech/elastic.h"

using namespace constitutive;

TEST_CASE("Elastic params (lambda, mu)", "[mech]") {
  LambdaMu<double> lambda_mu{100., 50.};
  REQUIRE(lambda_mu.get_lambda() == 100.);
  REQUIRE(lambda_mu.get_mu() == 50.);
  REQUIRE(lambda_mu.get_E() == 120);
  REQUIRE(lambda_mu.get_nu() == 0.3);
}

TEST_CASE("Elastic params (E, nu)", "[mech]") {
  YoungPoisson<double> params{120., 0.25};
  REQUIRE(params.get_E() == 120.);
  REQUIRE(params.get_nu() == 0.25);
  REQUIRE(params.get_lambda() == 100.);
  REQUIRE(params.get_mu() == 50.);
}

TEST_CASE("Convert lambda, mu to E, nu", "[mech]") {
  LambdaMu<double> lambda_mu(80., 60.);
  YoungPoisson young_poisson(lambda_mu);
  REQUIRE(young_poisson.get_E() == 100.);
  REQUIRE(young_poisson.get_nu() == 0.25);
}

TEST_CASE("Convert E, nu to lambda, mu", "[mech]") {
  YoungPoisson<double> young_poisson{100., 0.35};
  LambdaMu lambda_mu{young_poisson};
  REQUIRE(lambda_mu.get_lambda() == 90.);
  REQUIRE(lambda_mu.get_mu() == 60.);
}
