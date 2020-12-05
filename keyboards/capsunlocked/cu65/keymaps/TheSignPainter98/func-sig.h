#pragma once

/**
 * @brief A named function signature
 *
 * Useful for concisely writing the types of parameter function-pointers
 *
 * @param r Return type of the lambda, cannot be void
 * @param n Expression of the body of the lambda, must have non-void type
 * @param ps Parameters of the lambda
 *
 * @return The signature of a function-pointer of name `n` which takes `ps` and returns `r`
 */
#define func_sig(r, ps, n) r(*n) ps

/**
 * @brief A function type
 *
 * Useful for concisely writing the types of parameter function-pointers
 *
 * @param r Return type of the function signature
 * @param ps Parameters of the function
 *
 * @return The type of a function-pointer which takes `ps` and returns `r`
 */
#define func_type(r, ps) r(*) ps

#define func_arr(r, ps, n) r (*n[]) ps
#define func_arrs(r, ps, n, N) r (*n[N]) ps
