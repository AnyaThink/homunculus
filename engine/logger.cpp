#include "logger.h"

logger_t::logger_t (const char *fname_log)
{
  m_fstream.open (fname_log, std::ios_base::out);
}

logger_t::~logger_t ()
{
  m_fstream.flush ();
  m_fstream.close ();
}

const char *enum_to_string (log_section_t section)
{
  switch (section)
    {
    case log_section_t::ENGINE:
      return "ENGINE";
    case log_section_t::ERROR:
      return "Internal logger error";
    }
  return "Internal logger error";
}

const char *enum_to_string (log_priority_t priority)
{
  switch (priority)
    {
    case log_priority_t::INFO:
      return "info";
    case log_priority_t::WARNING:
      return "warning";
    case log_priority_t::ERROR:
      return "error";
    case log_priority_t::COUNT:
      return "Internal logger error";
    }
  return "Internal logger error";
}

