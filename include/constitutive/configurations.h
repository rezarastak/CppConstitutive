#pragma once

#include <deal.II/base/symmetric_tensor.h>

namespace constitutive {
namespace configs {
  /**
   * Provides default types based on deal.II types.
   */
  struct DealII {
    /**
     * Scalar type used for strains.
     */
    using StrainScalar = double;

    /**
     * The type used for small strain tensor.
     */
    template <int dim>
    using Strain = dealii::SymmetricTensor<2, dim>;

    /**
     * Scalar types used for stresses.
     */
    using StressScalar = double;

    /**
     * The types used for Couchy stress tensor.
     */
    template <int dim>
    using CauchyStress = dealii::SymmetricTensor<2, dim>;

    /**
     * Types used for materials parameters.
     */
    using ParamScalar = double;
  };
} // namespace configs
} // namespace constitutive
