project('A Simple Graphics Library sgfx', 'c',
        version: '1.0',
        license: 'LGPL-3.0',
        default_options: ['c_std=c99'])
x11_dep = dependency('x11')
# Disable strict aliasing
if meson.get_compiler('c').has_argument('-fno-strict-aliasing')
	extra_args = ['-fno-strict-aliasing']
endif
# Source & header files
inc = include_directories('include')

subdir('include')
subdir('src')
subdir('test')

# Generate pkg-config
pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries: libsgfx,
                 version: '3.0',
                 name: 'libsgfx',
                 filebase: 'sgfx',
                 description: 'A Simple Graphics Library (sgfx)')
# Meson dep
libsgfx_dep = declare_dependency(include_directories: inc, link_with: libsgfx)
