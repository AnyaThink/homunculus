#include "frame_manager.h"

#include <chrono>
#include <thread>

#include "common/string/string_utils.h"

using namespace chrono;

frame_manager::frame_manager ()
{
}

void frame_manager::start_frame ()
{
  assert_check (!m_last_frame_start.has_value (), "Don't call start twice in a row");

  m_last_frame_start = steady_clock::now ();
}

double frame_manager::to_double (const frame_manager::duration_t &d)
{
  return duration_cast<duration<double>> (d).count ();
}

std::string frame_manager::end_frame ()
{
  assert_check (m_last_frame_start.has_value (), "Don't call end before start");

  time_point_t end_time = steady_clock::now ();

  duration_t time_passed = duration_cast<duration_t> (end_time - *m_last_frame_start);
  m_last_frame_start = nullopt;

  if (time_passed >= frame_length_d)
    return "Freezing!";

  duration_t sleep_for = frame_length_d - time_passed;
  this_thread::sleep_for (sleep_for);
  double ratio = to_double (sleep_for) / to_double (frame_length_d);

  return string_printf ("Performance ratio: %.2lf", ratio);
}
