# Learning-C

This repository is a personal C programming archive built while learning through CS50x and independent practice. It contains weekly problem sets, small challenge implementations, and a few personal exploration files outside the course curriculum.

The focus here is mostly on learning fundamentals: control flow, arrays, strings, algorithms, memory, file I/O, and simple problem solving in C.

## Repository structure

```text
Learning-C/
├── Week-1/
│   ├── P-1/
│   │   ├── hello.c              # Basic first program; prints a greeting
│   │   └── hello                # Compiled binary
│   ├── P-2/
│   │   ├── hello.c              # Short intro exercise using C basics
│   │   └── me                   # Compiled binary
│   ├── P-3/
│   │   ├── mario.c              # Build a half-pyramid like the classic Mario problem
│   │   └── mario                # Compiled binary
│   ├── P-4/
│   │   ├── cash.c               # Greedy change-making problem (minimum coins)
│   │   └── cash                 # Compiled binary
│   ├── P-5/
│   │   ├── credit.c             # Luhn algorithm credit card validation
│   │   ├── credit(comments).c   # commented version of the same solution
│   │   └── credit               # Compiled binary
│   └── mario-more/
│       ├── mario.c              # Extended Mario pyramid problem with more complexity
│       └── mario                # Compiled binary
│
├── Week-2/
│   ├── caesar.c                 # Caesar cipher encryption challenge
│   ├── readability.c            # Compute reading grade level from text
│   ├── scrabble.c               # Score-based word comparison game
│   ├── caesar                   # Compiled binary
│   ├── readability              # Compiled binary
│   ├── output.log              # Logs / test output from running the program
│   └── 🎓                      # Placeholder / scratch marker
│
├── Week-3/
│   ├── plurality.c              # Voting system simulation using plurality rule
│   ├── runoff.c                 # Ranked voting simulation using runoff logic
│   ├── tideman.c                # Ranked-pairs / Tideman voting algorithm
│   ├── votes                   # Compiled binary
│   └── runoff                   # Compiled binary
│
├── Week-4/
│   ├── filter-less/
│   │   ├── filter.c             # Image manipulation challenge (grayscale/sepia/reverse)
│   │   ├── ex.c                 # Extra experimentation file
│   │   ├── sample.bmp           # Sample image input
│   │   ├── yard.bmp             # Example image used during testing
│   │   ├── output.bmp           # Generated output image
│   │   └── ...                  # Other BMP test assets
│   ├── input1.wav               # Audio sample for sound processing
│   ├── input2.wav               # Audio sample for sound processing
│   ├── volume.c                 # Audio volume adjustment challenge
│   └── volume                   # Compiled binary
│
├── Week-5/
│   └── milo.c                   # Small follow-up or practice-minded C file
│
├── sort_algos/
│   ├── bubble_sort.c            # Personal algorithm study: bubble sort
│   ├── insertion_sort.c         # Personal algorithm study: insertion sort
│   ├── merge_sort.c             # Personal algorithm study: merge sort
│   └── selection_sort.c         # Personal algorithm study: selection sort
│
├── extras/
│   ├── dblyllst.c               # Doubly linked list practice
│   ├── dtrmnt.c                 # Small data structure / memory exercise
│   ├── dymlst.c                 # Dynamic list implementation practice
│   ├── hashmap.c                # Hash map / hashing practice
│   ├── llsts.c                  # Linked list practice
│   ├── todo.c                   # Simple to-do list / task tracker exercise
│   ├── tree.c                   # Tree-based data structure practice
│   ├── hrr_gm/
│   │   └── ct.c                 # Extra hobby / experimentation file
│   ├── hash                     # Compiled binary
│   ├── dblyllst                 # Compiled binary
│   ├── dtrmnt                   # Compiled binary
│   ├── llsts                    # Compiled binary
│   └── ...
│
├── hex.c                        # Small hexadecimal / low-level numeric experiment
├── hex.s                        # Assembly equivalent / study file
├── test.c                       # Scratch test file for experimenting
├── test2                        # Another quick test binary or artifact
├── .gitignore                   # Git ignore rules
├── README.md                    # Project overview
└── LICENSE (if present)         # Project license (if added later)
```

## Week-by-week overview

### Week 1: Beginner C and problem-solving basics

These files are the classic CS50x starting exercises.

- hello.c / P-1: simple output and compilation basics.
- hello.c / P-2: a short introduction to printing/formatting in C.
- mario.c: generate a block pyramid using loops and nested iteration.
- cash.c: simulate coin-based change making using the greedy algorithm.
- credit.c: validate credit card numbers using the Luhn algorithm.
- mario-more.c: a more advanced version of the Mario challenge with additional pyramid logic.

### Week 2: Ciphers, text analysis, and game logic

- caesar.c: implement Caesar cipher encryption and decryption with key validation.
- readability.c: calculate an approximate reading grade using the Coleman-Liau index.
- scrabble.c: compare two players' word scores and determine the winner.

### Week 3: Voting systems and algorithmic decision-making

- plurality.c: choose a winner based on the highest number of votes.
- runoff.c: simulate elimination rounds in a runoff election.
- tideman.c: implement the Tideman ranked-pairs approach to determine a winner.

### Week 4: Media processing and file manipulation

- filter-less/filter.c: work with BMP images and apply filters such as grayscale or simple transformations.
- volume.c: adjust the loudness of audio files and manipulate WAV data.

### Week 5 and misc files

- milo.c: a smaller continuation or practice file in the same learning style.
- hex.c / hex.s: low-level exploration around numeric representation and assembly understanding.
- test.c / test2: personal scratch files used while learning and debugging small ideas.

## Personal progress and non-CS50x work

The folders below are not part of the official CS50x problem set, but they reflect independent study and growth.

### sort_algos/

This directory is focused on core algorithm learning and implementation practice.

- bubble_sort.c: sorting numbers by repeatedly swapping adjacent items.
- insertion_sort.c: building a sorted list one item at a time.
- selection_sort.c: repeatedly selecting the smallest remaining value.
- merge_sort.c: divide-and-conquer sorting approach.

These are not course assignments; they are personal algorithm exercises to improve understanding of sorting techniques and C program structure.

### extras/

This folder contains extra data structure and programming practice beyond the course material.

- linked list exercises: basic list operations and pointer-based structures.
- doubly linked list practice: more complex traversal and node relationships.
- hash map code: storing and retrieving data with hashing.
- tree structures: learning node-based recursive and non-recursive data structures.
- todo.c: a small task-management style file.
- other experimental files: quick ideas, practice snippets, and mini projects.

This folder represents a more personal, exploratory side of the repository: not problem-set work, but real growth in C fundamentals, memory management, and algorithmic thinking.

## Notes

- This repo is a learning archive, so some files are rough or experimental.
- The purpose is not perfection but progression.
- Many binaries in the repo are compiled outputs from running C programs during practice.
- The course-related folders are the main backbone of the project, while sort_algos and extras show independent exploration.

## Goals of the repository

- learn the fundamentals of C
- solve classic algorithmic programming problems
- practice data structures and memory management
- build confidence by writing small but meaningful programs
- keep a record of progress over time

If you keep exploring this repo, you can clearly see the progression from simple beginner tasks to more advanced problem solving and personal coding experiments.
