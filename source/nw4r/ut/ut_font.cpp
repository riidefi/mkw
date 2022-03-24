#include "ut_font.hpp"

namespace nw4r {
namespace ut {

void force_Font_dt() { ((Font*)nullptr)->~Font(); }

} // namespace ut
} // namespace nw4r
