#include <fenv.h>
#include <cstring>

#include "common/common.h"
#include "common/err_t.h"
#include "engine/engine.h"
#include "logic/tests/logic_tests.h"

int main (int argc, char *argv[])
{
  do_nothing (argc, argv);
  feenableexcept (FE_DIVBYZERO | FE_OVERFLOW | FE_INVALID);
  run_logic_tests ();

  if (argc > 1 && !strcmp (argv[1], "--tests-only"))
      return 0;

  engine_t engine (argc, argv);
  return engine.exec ();
}
