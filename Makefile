PROGRAM=rapidsvn

CXX=g++

OBJECTS=action_thread.o \
		add_action.o \
		auth_baton.o \
		checkout_action.o \
		checkout_dlg.o \
		commit_action.o \
		commit_dlg.o \
		copy_action.o \
		copy_dlg.o \
		delete_action.o \
		delete_dlg.o \
		exceptions.o \
		filelist_ctrl.o \
		folder_browser.o \
		import_action.o \
		import_dlg.o \
		include.o \
		merge_action.o \
		merge_dlg.o \
		mkdir_action.o \
		mkdir_dlg.o \
		notify.o \
		report_dlg.o \
		resolve_action.o \
		revert_action.o \
		svn_file_info.o \
		svn_file_log.o \
		svn_file_status.o \
		trace_commit.o \
		trace_update.o \
		tracer.o \
		update_action.o \
		update_dlg.o \
		utils.o \
		rapidsvn.o \
		rapidsvn_app.o

APR_LIBS=-L/usr/share/apache2/lib
LIBS=-lsvn_client-1 -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_subr-1 \
		$(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(APR_LIBS)
SVN_INC=-I/usr/local/include/subversion-1

# implementation

.SUFFIXES:	.o .cpp

.cpp.o:
	$(CXX) -c -g `wx-config --cxxflags` $(SVN_INC) -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CXX) -o $(PROGRAM)  $(LIBS) `wx-config --libs` $(OBJECTS)

clean: 
	rm -f *.o $(PROGRAM)
