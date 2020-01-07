#pragma once

#include "constitutive/exceptions.h"

namespace constitutive {

// Forward declaration
template <typename Param>
class YoungPoisson;

/**
 * Parameters used to describe the basic elastisicy of materials.
 * It stores the Lam{\'e} constants.
 */
template <typename Param>
class LambdaMu {
public:
  /**
   * Constructor. Lambda and mu must be positive values.
   */
  constexpr LambdaMu(Param lambda, Param mu) noexcept : lambda{lambda}, mu{mu} {
    Assert(lambda > 0., ExcParamOutOfRange());
    Assert(mu >= 0., ExcParamOutOfRange());
  }

  /**
   * Converting Constructor.
   */
  constexpr explicit LambdaMu(YoungPoisson<Param> params) noexcept;

  /**
   * Const lambda accessor.
   */
  constexpr Param get_lambda() const noexcept {
    return lambda;
  }

  /**
   * Const mu accessor.
   */
  constexpr Param get_mu() const noexcept {
    return mu;
  }

  /**
   * Compute the value of E from lambda and mu.
   */
  constexpr Param get_E() const noexcept {
    const auto temp = lambda / (lambda + mu);
    return mu * (temp + 2.); // = mu * (3 lambda + 2 mu) / (lambda + mu)
  }

  /**
   * Compute the value of nu from lambda and mu.
   */
  constexpr Param get_nu() const noexcept {
    return 0.5 * lambda / (lambda + mu);
  }

private:
  /**
   * The Lam{\'e} stiffness constant $\lambda$.
   */
  Param lambda;

  /**
   * The Lam{\'e} shear constant $\mu$.
   */
  Param mu;
};

/**
 * Deduction guide for constructor.
 */
template <typename Param>
LambdaMu(Param, Param)->LambdaMu<Param>;

/**
 * Deduction guide for converting constructor.
 */
template <typename Param>
LambdaMu(YoungPoisson<Param>)->LambdaMu<Param>;

/**
 * Stores the Young's modulus and Poissons ratio for an elastic materials.
 */
template <typename Param>
class YoungPoisson {
public:
  /**
   * Constructor.
   */
  constexpr YoungPoisson(Param E, Param nu) noexcept : E{E}, nu{nu} {
    Assert(E > 0., ExcParamOutOfRange());
    Assert(nu >= -1., ExcParamOutOfRange());
    Assert(nu < 0.5, ExcParamOutOfRange());
  }

  /**
   * Converting constructor.
   */
  constexpr explicit YoungPoisson(LambdaMu<Param> params) noexcept {
    const auto lambda = params.get_lambda();
    const auto mu = params.get_mu();
    const auto temp = lambda / (lambda + mu);
    E = mu * (temp + 2.); // = mu * (3 lambda + 2 mu) / (lambda + mu)
    nu = 0.5 * temp;      // = lambda / (2(lambda + mu))
  }

  /**
   * Const accessor for E.
   */
  constexpr Param get_E() const noexcept {
    return E;
  }

  /**
   * Const accessor for nu.
   */
  constexpr Param get_nu() const noexcept {
    return nu;
  }

  /**
   * Compute lambda from E and nu.
   */
  constexpr Param get_lambda() const noexcept {
    return E * nu / (1. - 2. * nu) / (1. + nu);
  }

  /**
   * Compute mu from E and nu.
   */
  constexpr Param get_mu() const noexcept {
    return 0.5 * E / (1. + nu);
  }

private:
  /**
   * The Young's modulus.
   */
  Param E;

  /**
   * The Poisson's ratio $\nu$.
   */
  Param nu;
};

/**
 * Deduction guide for constructor.
 */
template <typename Param>
YoungPoisson(Param, Param)->YoungPoisson<Param>;

/**
 * Deduction guide for converting constructor.
 */
template <typename Param>
YoungPoisson(LambdaMu<Param>)->YoungPoisson<Param>;

/*---------------------- inline functions ----------------------------*/
template <typename Param>
constexpr LambdaMu<Param>::LambdaMu(YoungPoisson<Param> params) noexcept {
  const auto temp = params.get_E() / (1. + params.get_nu());
  // lambda = E nu / ((1 + nu)(1 - 2 nu))
  lambda = temp * params.get_nu() / (1. - 2. * params.get_nu());
  // mu = E / (2(1 + nu))
  mu = 0.5 * temp;
}
} // namespace constitutive
