#pragma once

/**
 * \file Contains uniaxial driviers.
 */

namespace constitutive {

/**
 * Create and advance a displacement-controlled uniaxial simulation.
 * If the material implements a uniaxial method, it will be used by this
 * class, otherwise it will use the default 3D implementation of materials.
 * @tparam Material: material class used to run this simulation.
 * @tparam TimeControl: the control class that takes care of time-stepping
 * and determining the size of dt.
 */
template <typename Material, typename TimeControl>
struct uniaxial {
  /**
   * Hold the material data.
   */
  Material material;

  /**
   * Hold time-stepping data.
   */
  TimeControl time;

  /**
   * Run a single time-step.
   */
};
}
