// Automatically generated by odin 1.2.7 - do not edit
#include <float.h>
#include <R.h>
#include <Rmath.h>
#include <Rinternals.h>
#include <stdbool.h>
#include <R_ext/Rdynload.h>
typedef struct gen_fr_model_internal {
  double f_max;
  double initial_n;
  double n_half;
  double n_initial;
  double p;
  double q;
} gen_fr_model_internal;
gen_fr_model_internal* gen_fr_model_get_internal(SEXP internal_p, int closed_error);
static void gen_fr_model_finalise(SEXP internal_p);
SEXP gen_fr_model_create(SEXP user);
void gen_fr_model_initmod_desolve(void(* odeparms) (int *, double *));
SEXP gen_fr_model_contents(SEXP internal_p);
SEXP gen_fr_model_set_user(SEXP internal_p, SEXP user);
SEXP gen_fr_model_set_initial(SEXP internal_p, SEXP t_ptr, SEXP state_ptr, SEXP gen_fr_model_use_dde_ptr);
SEXP gen_fr_model_metadata(SEXP internal_p);
SEXP gen_fr_model_initial_conditions(SEXP internal_p, SEXP t_ptr);
void gen_fr_model_rhs(gen_fr_model_internal* internal, double t, double * state, double * dstatedt, double * output);
void gen_fr_model_rhs_dde(size_t neq, double t, double * state, double * dstatedt, void * internal);
void gen_fr_model_rhs_desolve(int * neq, double * t, double * state, double * dstatedt, double * output, int * np);
SEXP gen_fr_model_rhs_r(SEXP internal_p, SEXP t, SEXP state);
double user_get_scalar_double(SEXP user, const char *name,
                              double default_value, double min, double max);
int user_get_scalar_int(SEXP user, const char *name,
                        int default_value, double min, double max);
void user_check_values_double(double * value, size_t len,
                                  double min, double max, const char *name);
void user_check_values_int(int * value, size_t len,
                               double min, double max, const char *name);
void user_check_values(SEXP value, double min, double max,
                           const char *name);
SEXP user_list_element(SEXP list, const char *name);
double scalar_real(SEXP x, const char * name);
gen_fr_model_internal* gen_fr_model_get_internal(SEXP internal_p, int closed_error) {
  gen_fr_model_internal *internal = NULL;
  if (TYPEOF(internal_p) != EXTPTRSXP) {
    Rf_error("Expected an external pointer");
  }
  internal = (gen_fr_model_internal*) R_ExternalPtrAddr(internal_p);
  if (!internal && closed_error) {
    Rf_error("Pointer has been invalidated");
  }
  return internal;
}
void gen_fr_model_finalise(SEXP internal_p) {
  gen_fr_model_internal *internal = gen_fr_model_get_internal(internal_p, 0);
  if (internal_p) {
    R_Free(internal);
    R_ClearExternalPtr(internal_p);
  }
}
SEXP gen_fr_model_create(SEXP user) {
  gen_fr_model_internal *internal = (gen_fr_model_internal*) R_Calloc(1, gen_fr_model_internal);
  internal->f_max = NA_REAL;
  internal->n_half = NA_REAL;
  internal->n_initial = NA_REAL;
  internal->p = NA_REAL;
  internal->q = NA_REAL;
  SEXP ptr = PROTECT(R_MakeExternalPtr(internal, R_NilValue, R_NilValue));
  R_RegisterCFinalizer(ptr, gen_fr_model_finalise);
  UNPROTECT(1);
  return ptr;
}
static gen_fr_model_internal *gen_fr_model_internal_ds;
void gen_fr_model_initmod_desolve(void(* odeparms) (int *, double *)) {
  static DL_FUNC get_desolve_gparms = NULL;
  if (get_desolve_gparms == NULL) {
    get_desolve_gparms =
      R_GetCCallable("deSolve", "get_deSolve_gparms");
  }
  gen_fr_model_internal_ds = gen_fr_model_get_internal(get_desolve_gparms(), 1);
}
SEXP gen_fr_model_contents(SEXP internal_p) {
  gen_fr_model_internal *internal = gen_fr_model_get_internal(internal_p, 1);
  SEXP contents = PROTECT(allocVector(VECSXP, 6));
  SET_VECTOR_ELT(contents, 0, ScalarReal(internal->f_max));
  SET_VECTOR_ELT(contents, 1, ScalarReal(internal->initial_n));
  SET_VECTOR_ELT(contents, 2, ScalarReal(internal->n_half));
  SET_VECTOR_ELT(contents, 3, ScalarReal(internal->n_initial));
  SET_VECTOR_ELT(contents, 4, ScalarReal(internal->p));
  SET_VECTOR_ELT(contents, 5, ScalarReal(internal->q));
  SEXP nms = PROTECT(allocVector(STRSXP, 6));
  SET_STRING_ELT(nms, 0, mkChar("f_max"));
  SET_STRING_ELT(nms, 1, mkChar("initial_n"));
  SET_STRING_ELT(nms, 2, mkChar("n_half"));
  SET_STRING_ELT(nms, 3, mkChar("n_initial"));
  SET_STRING_ELT(nms, 4, mkChar("p"));
  SET_STRING_ELT(nms, 5, mkChar("q"));
  setAttrib(contents, R_NamesSymbol, nms);
  UNPROTECT(2);
  return contents;
}
SEXP gen_fr_model_set_user(SEXP internal_p, SEXP user) {
  gen_fr_model_internal *internal = gen_fr_model_get_internal(internal_p, 1);
  internal->f_max = user_get_scalar_double(user, "f_max", internal->f_max, NA_REAL, NA_REAL);
  internal->n_half = user_get_scalar_double(user, "n_half", internal->n_half, NA_REAL, NA_REAL);
  internal->n_initial = user_get_scalar_double(user, "n_initial", internal->n_initial, NA_REAL, NA_REAL);
  internal->p = user_get_scalar_double(user, "p", internal->p, NA_REAL, NA_REAL);
  internal->q = user_get_scalar_double(user, "q", internal->q, NA_REAL, NA_REAL);
  internal->initial_n = internal->n_initial;
  return R_NilValue;
}
SEXP gen_fr_model_set_initial(SEXP internal_p, SEXP t_ptr, SEXP state_ptr, SEXP gen_fr_model_use_dde_ptr) {
  return R_NilValue;
}
SEXP gen_fr_model_metadata(SEXP internal_p) {
  gen_fr_model_internal *internal = gen_fr_model_get_internal(internal_p, 1);
  SEXP ret = PROTECT(allocVector(VECSXP, 4));
  SEXP nms = PROTECT(allocVector(STRSXP, 4));
  SET_STRING_ELT(nms, 0, mkChar("variable_order"));
  SET_STRING_ELT(nms, 1, mkChar("output_order"));
  SET_STRING_ELT(nms, 2, mkChar("n_out"));
  SET_STRING_ELT(nms, 3, mkChar("interpolate_t"));
  setAttrib(ret, R_NamesSymbol, nms);
  SEXP variable_length = PROTECT(allocVector(VECSXP, 1));
  SEXP variable_names = PROTECT(allocVector(STRSXP, 1));
  setAttrib(variable_length, R_NamesSymbol, variable_names);
  SET_VECTOR_ELT(variable_length, 0, R_NilValue);
  SET_STRING_ELT(variable_names, 0, mkChar("n"));
  SET_VECTOR_ELT(ret, 0, variable_length);
  UNPROTECT(2);
  SET_VECTOR_ELT(ret, 1, R_NilValue);
  SET_VECTOR_ELT(ret, 2, ScalarInteger(0));
  UNPROTECT(2);
  return ret;
}
SEXP gen_fr_model_initial_conditions(SEXP internal_p, SEXP t_ptr) {
  gen_fr_model_internal *internal = gen_fr_model_get_internal(internal_p, 1);
  SEXP r_state = PROTECT(allocVector(REALSXP, 1));
  double * state = REAL(r_state);
  state[0] = internal->initial_n;
  UNPROTECT(1);
  return r_state;
}
void gen_fr_model_rhs(gen_fr_model_internal* internal, double t, double * state, double * dstatedt, double * output) {
  double n = state[0];
  dstatedt[0] = -(internal->f_max) * pow(n, (1 + internal->q)) / (double) (pow(internal->n_half, (1 + internal->q)) + pow(n, (1 + internal->q))) * internal->p;
}
void gen_fr_model_rhs_dde(size_t neq, double t, double * state, double * dstatedt, void * internal) {
  gen_fr_model_rhs((gen_fr_model_internal*)internal, t, state, dstatedt, NULL);
}
void gen_fr_model_rhs_desolve(int * neq, double * t, double * state, double * dstatedt, double * output, int * np) {
  gen_fr_model_rhs(gen_fr_model_internal_ds, *t, state, dstatedt, output);
}
SEXP gen_fr_model_rhs_r(SEXP internal_p, SEXP t, SEXP state) {
  SEXP dstatedt = PROTECT(allocVector(REALSXP, LENGTH(state)));
  gen_fr_model_internal *internal = gen_fr_model_get_internal(internal_p, 1);
  double *output = NULL;
  gen_fr_model_rhs(internal, scalar_real(t, "t"), REAL(state), REAL(dstatedt), output);
  UNPROTECT(1);
  return dstatedt;
}
double user_get_scalar_double(SEXP user, const char *name,
                              double default_value, double min, double max) {
  double ret = default_value;
  SEXP el = user_list_element(user, name);
  if (el != R_NilValue) {
    if (length(el) != 1) {
      Rf_error("Expected a scalar numeric for '%s'", name);
    }
    if (TYPEOF(el) == REALSXP) {
      ret = REAL(el)[0];
    } else if (TYPEOF(el) == INTSXP) {
      ret = INTEGER(el)[0];
    } else {
      Rf_error("Expected a numeric value for '%s'", name);
    }
  }
  if (ISNA(ret)) {
    Rf_error("Expected a value for '%s'", name);
  }
  user_check_values_double(&ret, 1, min, max, name);
  return ret;
}
int user_get_scalar_int(SEXP user, const char *name,
                        int default_value, double min, double max) {
  int ret = default_value;
  SEXP el = user_list_element(user, name);
  if (el != R_NilValue) {
    if (length(el) != 1) {
      Rf_error("Expected scalar integer for '%d'", name);
    }
    if (TYPEOF(el) == REALSXP) {
      double tmp = REAL(el)[0];
      if (fabs(tmp - round(tmp)) > 2e-8) {
        Rf_error("Expected '%s' to be integer-like", name);
      }
    }
    ret = INTEGER(coerceVector(el, INTSXP))[0];
  }
  if (ret == NA_INTEGER) {
    Rf_error("Expected a value for '%s'", name);
  }
  user_check_values_int(&ret, 1, min, max, name);
  return ret;
}
void user_check_values_double(double * value, size_t len,
                                  double min, double max, const char *name) {
  for (size_t i = 0; i < len; ++i) {
    if (ISNA(value[i])) {
      Rf_error("'%s' must not contain any NA values", name);
    }
  }
  if (min != NA_REAL) {
    for (size_t i = 0; i < len; ++i) {
      if (value[i] < min) {
        Rf_error("Expected '%s' to be at least %g", name, min);
      }
    }
  }
  if (max != NA_REAL) {
    for (size_t i = 0; i < len; ++i) {
      if (value[i] > max) {
        Rf_error("Expected '%s' to be at most %g", name, max);
      }
    }
  }
}
void user_check_values_int(int * value, size_t len,
                               double min, double max, const char *name) {
  for (size_t i = 0; i < len; ++i) {
    if (ISNA(value[i])) {
      Rf_error("'%s' must not contain any NA values", name);
    }
  }
  if (min != NA_REAL) {
    for (size_t i = 0; i < len; ++i) {
      if (value[i] < min) {
        Rf_error("Expected '%s' to be at least %g", name, min);
      }
    }
  }
  if (max != NA_REAL) {
    for (size_t i = 0; i < len; ++i) {
      if (value[i] > max) {
        Rf_error("Expected '%s' to be at most %g", name, max);
      }
    }
  }
}
void user_check_values(SEXP value, double min, double max,
                           const char *name) {
  size_t len = (size_t)length(value);
  if (TYPEOF(value) == INTSXP) {
    user_check_values_int(INTEGER(value), len, min, max, name);
  } else {
    user_check_values_double(REAL(value), len, min, max, name);
  }
}
SEXP user_list_element(SEXP list, const char *name) {
  SEXP ret = R_NilValue, names = getAttrib(list, R_NamesSymbol);
  for (int i = 0; i < length(list); ++i) {
    if (strcmp(CHAR(STRING_ELT(names, i)), name) == 0) {
      ret = VECTOR_ELT(list, i);
      break;
    }
  }
  return ret;
}
double scalar_real(SEXP x, const char * name) {
  if (Rf_length(x) != 1) {
    Rf_error("Expected a scalar for '%s'", name);
  }
  double ret = 0.0;
  if (TYPEOF(x) == INTSXP) {
    ret = INTEGER(x)[0];
  } else if (TYPEOF(x) == REALSXP) {
    ret = REAL(x)[0];
  } else {
    Rf_error("Expected a numeric value for '%s'", name);
  }
  return ret;
}
