#pragma once

namespace constitutive {
/**
 * Parameters used to describe the basic elastisicy of materials.
 * It stores the Lam{\'e} constants.
 */
template <typename Param>
struct LambdaMu {
public:
  /**
   * Constructor. Lambda and mu must be positive values.
   */
  constexpr LambdaMu(Param lambda, Param mu) : lambda{lambda}, mu { mu }
  noexcept {
    Assert(lambda > 0., ParamOutOfRange());
    Assert(mu >= 0., ParamOutOfRange());
  }

  /**
   * Converting Constructor.
   */
  constexpr explicit LambdaMu(YoungPoisson params) noexcept;

  /**
   * Const lambda accessor.
   */
  constexpr Param get_lambda() const { return lambda; }

  /**
   * Const mu accessor.
   */
  constexpr Param get_mu() const { return mu; }

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
 * Stores the Young's modulus and Poissons ratio for an elastic materials.
 */
template <typename Param>
struct YoungPoisson {
public:
  /**
   * Constructor.
   */
  constexpr YoungPoisson(Param E, Param nu) : E{E}, nu { nu }
  noexcept {
    Assert(E > 0., ParamOutOfRange());
    Assert(nu >= -1., ParamOutOfRange());
    Assert(nu < 0.5, ParamOutOfRange());
  }

  /**
   * Converting constructor.
   */
  constexpr explicit YoungPoisson(LambdaMu<Param> params) noexcept {
    const auto temp = params.lambda / (params.lambda + params.mu);
    E = params.mu * (temp + 2.); // = mu * (3 lambda + 2 mu) / (lambda + mu)
    nu = 0.5 * temp;             // = lambda / (2(lambda + mu))
  }

  /**
   * Const accessor for E.
   */
  constexpr Param get_E() const noexcept { return E; }

  /**
   * Const accessor for nu.
   */
  constexpr Param get_nu() const noexcept { return nu; }

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

/*---------------------- inline functions ----------------------------*/
template <typename Param>
constexpr LambdaMu<Param>::LambdaMu(YoungPoisson params) noexcept {
  const auto temp = params.E / (1. + params.nu);
  lambda = temp * params.nu / (1. - 2. * params.nu);
  mu = 0.5 * temp;
}
} // namespace constitutive
