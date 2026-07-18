default_toolchain := "stable"
nightly_toolchain := "nightly"

build:
    @cargo +{{default_toolchain}} build

check:
    @cargo +{{default_toolchain}} check

test:
    @cargo +{{default_toolchain}} test

clippy:
    @cargo +{{default_toolchain}} clippy

fmt:
    @cargo +{{nightly_toolchain}} fmt

fmt-check:
    @cargo +{{nightly_toolchain}} fmt -- --check

fix:
    @cargo +{{default_toolchain}} clippy --fix --allow-dirty
    @cargo +{{nightly_toolchain}} fmt

lint: fmt-check clippy
