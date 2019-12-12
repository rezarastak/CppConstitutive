#pragma once

#include <deal.II/base/symmetric_tensor.h>

namespace constitutive {
namespace configs {
  /**
   * Provides default types based on DealII types.
   */
  struct DealII {
    /**
     * The type used for small strain tensor.
     */
    template <int dim>
    using Strain = dealii::SymmetricTensor<2, dim>;

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
