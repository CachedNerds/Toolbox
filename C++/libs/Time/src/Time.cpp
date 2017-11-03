#include <Toolbox/Time/Time.h>
#include <ctime>
#include <chrono>

namespace Toolbox::Time
{
namespace {

const std::string removeTrailingNewline (const std::string & text)
{
  return text.substr (0, text.length () - 1);
}

} // end anonymous namespace 

const std::string getCurrentTime (void) 
{
  std::time_t now = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now ());
  std::tm localNow;
#ifdef _WIN32
  // localtime_s is not in namespace std on vc++ libraries for some reason
  localtime_s(&localNow, &now);
#else
  localtime_r(&now, &localNow);
#endif

  constexpr int dateSize = 26;
  char format[] = "%c";
  char timestamp[dateSize];
  std::strftime(timestamp, dateSize, format, &localNow);
  return removeTrailingNewline (timestamp);
}

} // namespace Toolbox::Time