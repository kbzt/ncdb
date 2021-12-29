ncdb_sources = files(
    'main.c',
    'getInfo.c',
    'ui.c',
)

ncdb_deps = [
    libcurl,
    jsonc,
]

executable(
    'ncdb', 
    ncdb_sources, 
    dependencies: ncdb_deps
)