# Repository Guidelines

## Project Structure & Module Organization

Put production code in `src/`, public headers in `include/`, and tests in `tests/`. Keep one structure per module, for example `include/stack.hpp` and `src/stack.cpp`. Put examples in `examples/`; do not commit generated output.

## Build, Test, and Development Commands

Use CMake with the C++17 compiler configured on the machine. Build and test locally with:

```powershell
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

These commands configure, compile, and run CTest. Keep build artifacts in `build/`, ignored by Git.

## Communication

Reply in Chinese, even when the contributor writes in English.

## Coding Style & Naming Conventions

Use C++17 or newer unless specified otherwise. Indent with four spaces; put braces on their own line. Name types in `PascalCase`; name functions, variables, and constants in `snake_case`. Prefer small, focused classes and RAII; avoid raw owning pointers. Keep headers self-contained.

## Learning Workflow

This is a C++ and data-structures learning repository. For normal exercises, use the following modes:

- **YOU WRITE:** You write the code before Codex offers implementation.
- **CODEX REVIEW:** Codex reviews your code without rewriting it and gives at most one hint at a time.
- **CODEX DEBUG:** You analyze the bug first; Codex then helps debug it incrementally.
- **CODEX IMPLEMENT:** Use only for larger project components when you explicitly request implementation.

Do not provide a complete exercise answer immediately. Explain *why* an approach works, not merely what to type. Prefer simple C++17 solutions unless the lesson requires another standard. When useful, relate structures and algorithms to ADAS or autonomous-driving scenarios, such as queues for sensor events.

## Testing Guidelines

Add tests in `tests/` alongside each new structure, using descriptive names such as `stack_pop_empty_throws`. Cover normal behavior, boundaries, invalid inputs, copy/move behavior, and ownership. Use a lightweight C++ test framework (for example, Catch2 or GoogleTest), and register tests with CTest.

## Commit & Pull Request Guidelines

There is no commit history yet; use concise imperative commits such as `Add linked-list insert tests`. Keep each commit small and focused. Before suggesting a commit, ask the contributor to run or review the relevant tests. Pull requests should explain the data structure or behavior changed, list test commands and results, link relevant issues, and include examples or screenshots only when they clarify user-visible output.
