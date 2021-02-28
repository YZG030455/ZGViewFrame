qtinstall = $$[QT_INSTALL_PREFIX]
msversion = $$basename(qtinstall)
qtverion = $$[QT_VERSION]

CONFIG(debug, debug|release) {
    DLLDESTDIR = $$PWD/build_out/$${qtverion}_$${msversion}_debug
    DESTDIR = $$PWD/build_out/$${qtverion}_$${msversion}_debug
} else {
    DLLDESTDIR = $$PWD/build_out/$${qtverion}_$${msversion}_release
    DESTDIR = $$PWD/build_out/$${qtverion}_$${msversion}_release
}

bin_path = $$DESTDIR

core_path = $$PWD/core

#多媒体插件



