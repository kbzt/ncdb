ncdb_sources = files(
    'main.c',
    'getInfo.c',
)

ncdb_deps = [
    libcurl,
]

executable(
    'ncdb', 
    ncdb_sources, 
    dependencies: ncdb_deps
)