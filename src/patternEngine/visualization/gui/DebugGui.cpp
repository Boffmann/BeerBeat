#include "DebugGui.h"

#include <vector>
#include <memory>
#include <string>

DebugGui::DebugGui() :

    _dispatcher()
{
    _dispatcher.connect(sigc::mem_fun(*this, &DebugGui::on_update_notification));
    set_title("Beer Beat Debug Window");
    set_default_size(200, 200);
    set_resizable(false);
    set_child(m_ledArea);
}

DebugGui::~DebugGui() {}

void DebugGui::draw_pattern(const std::shared_ptr<const Pattern> pattern) {
    _pattern = pattern;
    _dispatcher.emit();
}

void DebugGui::on_update_notification() {
    m_ledArea.draw_pattern(_pattern);
}


