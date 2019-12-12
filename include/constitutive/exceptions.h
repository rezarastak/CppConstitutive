#pragma once

#include <deal.II/base/exceptions.h>

/**
 * Exception for out of range material parameters.
 */
DeclExceptionMsg(
    ExcParamOutOfRange,
    "The parameter provided to the material model is out of range or invalid");
