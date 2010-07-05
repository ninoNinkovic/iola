/* -*- Mode: C++ ; c-basic-offset: 8 -*- */
#ifndef IOLA_DOMAIN_IPROJECT_H
#define IOLA_DOMAIN_IPROJECT_H

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

// BOOST
#include <boost/filesystem.hpp>
#include <boost/signals2.hpp>

// MLT
#include <mlt++/Mlt.h>

// IOLA
#include <iola/iunknown.h>

namespace iola
{
namespace domain
{

////////////////////////////////////////////////////////////////////////////
// class iola::domain::iproject

class iproject :
	public virtual iola::iunknown
{
public:
	virtual Mlt::Profile& get_profile() = 0;
	virtual Mlt::Producer& get_source() = 0;
	virtual Mlt::Producer& get_program() = 0;

	// Source
	virtual void source_new() = 0;
	virtual void source_load(boost::filesystem::path clip) = 0;
	virtual double source_get_speed() = 0;
	virtual void source_set_speed(double speed) = 0;
	virtual void source_seek(int position) = 0;

	virtual void source_step_forward() = 0;
	virtual void source_step_backward() = 0;
	virtual void source_play_forward() = 0;
	virtual void source_play_reverse() = 0;
	virtual void source_pause() = 0;
	virtual int source_get_mark_in() = 0;
	virtual int source_get_mark_out() = 0;
	virtual void source_set_mark_in() = 0;
	virtual void source_set_mark_out() = 0;
	virtual void source_set_mark_clip() = 0;
	virtual void source_clear_mark_in() = 0;
	virtual void source_clear_mark_out() = 0;
	virtual void source_goto_mark_in() = 0;
	virtual void source_goto_mark_out() = 0;
	virtual void source_goto_start() = 0;
	virtual void source_goto_end() = 0;

	// Program
	virtual void program_new() = 0;
	virtual void program_load(boost::filesystem::path sequence) = 0;
	virtual void program_save(boost::filesystem::path sequence) = 0;
	virtual void program_set_duration(int duration) = 0;
	virtual int program_get_duration() = 0;
	virtual void program_set_speed(double speed) = 0;
	virtual double program_get_speed() = 0;
	virtual void program_seek(int position) = 0;

	virtual int program_get_clip_count() = 0;
	virtual Mlt::ClipInfo* program_get_clip_info(int index) = 0;

	virtual void program_step_forward() = 0;
	virtual void program_step_backward() = 0;
	virtual void program_play_forward() = 0;
	virtual void program_play_reverse() = 0;
	virtual void program_pause() = 0;
	virtual int program_get_mark_in() = 0;
	virtual int program_get_mark_out() = 0;
	virtual void program_set_mark_in() = 0;
	virtual void program_set_mark_out() = 0;
	virtual void program_set_mark_cut() = 0;
	virtual void program_clear_mark_in() = 0;
	virtual void program_clear_mark_out() = 0;
	virtual void program_goto_mark_in() = 0;
	virtual void program_goto_mark_out() = 0;
	virtual void program_goto_previous_edit() = 0;
	virtual void program_goto_next_edit() = 0;
	virtual void program_goto_start() = 0;
	virtual void program_goto_end() = 0;
	virtual void program_insert() = 0;
	virtual void program_insert(boost::filesystem::path resource, const int program_in,
				    const int source_in, const int source_out) = 0;
	virtual void program_overwrite() = 0;
	virtual void program_overwrite(boost::filesystem::path resource, const int program_in,
				       const int source_in, const int source_out) = 0;

	// Signals
	typedef boost::signals2::signal<void ()> signal_t;

	signal_t on_source_load_signal;
	signal_t on_source_playback_signal;
	signal_t on_source_seek_signal;
	signal_t on_source_marks_change_signal;

	signal_t on_program_load_signal;
	signal_t on_program_playback_signal;
	signal_t on_program_seek_signal;
	signal_t on_program_marks_change_signal;
};

} // namespace domain
} // namespace iola

#endif // IOLA_DOMAIN_IPROJECT_H