#include "DebugApplication.h"
#include "DebugGui.h"

#include <iostream>

DebugApplication::DebugApplication()
: Gtk::Application("org.gtkmm.examples.application", Gio::Application::Flags::HANDLES_OPEN)
{
}

Glib::RefPtr<DebugApplication> DebugApplication::create()
{
  return Glib::make_refptr_for_instance<DebugApplication>(new DebugApplication());
}

void DebugApplication::create_debugwindow()
{
  _gui = new DebugGui();

  // Make sure that the application runs for as long this window is still open.
  add_window(*_gui);

  // A window can be added to an application with Gtk::Application::add_window()
  // or Gtk::Window::set_application(). When all added windows have been hidden
  // or removed, the application stops running (Gtk::Application::run() returns()),
  // unless Gio::Application::hold() has been called.

  // Delete the window when it is hidden.
  _gui->signal_hide().connect(sigc::bind(sigc::mem_fun(*this,
    &DebugApplication::on_hide_window), _gui));
}

void DebugApplication::on_activate()
{
  // The application has been started, so let's show a window.
  create_debugwindow();
  _gui->present();
}

void DebugApplication::on_hide_window(Gtk::Window* window)
{
  delete window;
}


void DebugApplication::showPattern(const std::shared_ptr<const Pattern> pattern) {
    std::cout << "Pattern " << std::endl;
    _gui->draw_pattern(pattern);
}

