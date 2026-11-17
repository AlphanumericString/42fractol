{ pkgs ? import <nixpkgs> { } }:

let
  x11Libs = with pkgs; [
    libx11
    libxext
    libxrandr
    libxcursor
    libxinerama
    libxi
  ];

  # MiniLibX's configure script only probes hardcoded FHS paths such as
  # /usr/include, which do not exist on NixOS. Merge the X11 dev headers into
  # one prefix and point configure at it through X11_INCLUDE.
  x11Headers = pkgs.buildEnv {
    name = "mlx-x11-headers";
    paths = [
      pkgs.libx11.dev
      pkgs.libxext.dev
      pkgs.xorgproto
    ];
    pathsToLink = [ "/include" ];
    ignoreCollisions = true;
  };
in
pkgs.mkShell {
  name = "42fractol";

  packages = [
    pkgs.clang
    pkgs.gnumake
    pkgs.pkg-config
    pkgs.gdb
    pkgs.libbsd
  ] ++ x11Libs;

  X11_INCLUDE = "${x11Headers}/include";

  # Make the X11 shared objects available when running ./fractol from the shell.
  LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath x11Libs;

  shellHook = ''
    echo "42fractol development shell"
    echo "  clang:      $(clang --version | head -n1)"
    echo "  X11 include: $X11_INCLUDE"
    echo "  build with:  make re"
  '';
}
