# Auto-generated by IDE. All changes by user will be lost!
# Created at 25/03/13 9:01 PM

BASEDIR = $$_PRO_FILE_PWD_

INCLUDEPATH +=  \
    $$BASEDIR/src/sql \
    $$BASEDIR/src

SOURCES +=  \
    $$BASEDIR/src/HandRecog.cpp \
    $$BASEDIR/src/LazyScholar.cpp \
    $$BASEDIR/src/Paint.cpp \
    $$BASEDIR/src/main.cpp \
    $$BASEDIR/src/Quiz.cpp \
    $$BASEDIR/src/soundmanager.cpp \
    $$BASEDIR/src/sql/DictionaryDAO.cpp

HEADERS +=  \
    $$BASEDIR/src/HandRecog.hpp \
    $$BASEDIR/src/LazyScholar.hpp \
    $$BASEDIR/src/Paint.hpp \
    $$BASEDIR/src/Quiz.hpp \
    $$BASEDIR/src/soundmanager.h \
    $$BASEDIR/src/sql/DictionaryDAO.hpp \
    $$BASEDIR/src/sql/DictionaryVO.hpp

CONFIG += precompile_header
PRECOMPILED_HEADER = $$BASEDIR/precompiled.h

lupdate_inclusion {
    SOURCES += \
        $$BASEDIR/../assets/*.qml
}

TRANSLATIONS = \
    $${TARGET}.ts

