project('LifeSimulator', 'cpp', 
  version: '0.1', 
  default_options: ['cpp_std=c++17']
)

ncurses_dep = dependency('ncurses')

src = files('src/main.cpp',
            'src/grid.cpp',
            'src/life_simulator.cpp')

executable('life_simulator', src, dependencies: ncurses_dep)
