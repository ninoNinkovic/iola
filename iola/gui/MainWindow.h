/* -*- Mode: C++ ; c-basic-offset: 8 -*- */
#ifndef IOLA_GUI_MAINWINDOW_H
#define IOLA_GUI_MAINWINDOW_H

// Iola NLE
// Copyright (c) 2010, Anders Dahnielson
//
// Contact: anders@dahnielson.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

// STD
#include <string>

// BOOST
#include <boost/filesystem.hpp>
#include <boost/signals2.hpp>

// FLTK
#include "fltk.h"

namespace iola
{
namespace gui
{

class ProgramMonitor;
class SourceMonitor;

class MainWindow :
	public Fl_Double_Window
{
public:
	MainWindow();
	~MainWindow();

	void open_project();
	void save_project();
	void save_as_project();
	void clear_project();
	void quit_application();

private:
	SourceMonitor* m_pkSourceMonitor;
	ProgramMonitor* m_pkProgramMonitor;

	boost::filesystem::path m_kProjectPath;

	void on_alert(std::string);

	boost::signals2::connection on_alert_connection;

	static void new_project(Fl_Widget*, void* v) { reinterpret_cast<MainWindow*>(v)->clear_project(); }
	static void open_project(Fl_Widget*, void* v) { reinterpret_cast<MainWindow*>(v)->open_project(); }
	static void save_project(Fl_Widget*, void* v) { reinterpret_cast<MainWindow*>(v)->save_project(); }
	static void save_as_project(Fl_Widget*, void* v) { reinterpret_cast<MainWindow*>(v)->save_as_project(); }
	static void quit_application(Fl_Widget*, void* v) { reinterpret_cast<MainWindow*>(v)->quit_application(); }
	static void close_window(Fl_Widget*, void* v) { reinterpret_cast<MainWindow*>(v)->close_window(); }
};

} // namespace gui
} // namespace iola

#endif // IOLA_GUI_MAINWINDOW_H
