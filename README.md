[README.md](https://github.com/user-attachments/files/34091301/README.md)
# Smart University Timetable, Classroom Allocation & Attendance Management System

A college **Design and Analysis of Algorithms (DAA)** project with a polished browser dashboard and a separately compilable **C timetable engine**.

## Architecture
- `index.html`, `css/`, `js/` — interactive website. The browser implementation mirrors the C scheduling workflow so the demonstration is reliable without a C/JavaScript bridge.
- `c-engine/` — the authoritative DAA implementation in standard C: sorting, greedy candidate assignment, conflict detection, searching and real recursive backtracking.
- `data/sample-data.json` — sample university data for documentation/integration.
- `docs/algorithm-explanation.md` — viva-friendly algorithm explanation and complexity.

The browser does **not** import or execute C source code. This is intentional and documented.

## macOS: run the website
Python 3 is commonly available with developer/Python setups. From the project root:

```bash
python3 -m http.server 8787
```

Open:

```text
http://localhost:8787
```

If port 8787 is busy:

```bash
python3 -m http.server 9000
```

Then open `http://localhost:9000`.

You can also open `index.html` directly, but using the local server is recommended.

## macOS: compile and demonstrate the C DAA engine
Check the compiler:

```bash
cc --version
```

If macOS says developer tools are missing:

```bash
xcode-select --install
```

Then:

```bash
cd c-engine
make clean
make
./timetable_engine
```

Expected behavior: it prints a valid timetable and real counters for assignments attempted, rejected conflicts and backtracking operations.

## Clean/rebuild C engine

```bash
cd c-engine
make clean
make
```

## Website features
- Dashboard KPIs, weekly attendance and classroom utilization
- Today's classes and recent activity
- Smart Timetable Generator with actual scheduling statistics
- Interactive weekly timetable
- Searchable teachers, subjects, classrooms and students
- Attendance percentages with below-75% highlighting
- Conflict detection
- Algorithm visualizer
- DAA algorithm analysis and complexity
- Reports and printable views
- Local settings persisted with `localStorage`

## DAA algorithms
1. **Sorting** — insertion sort prioritizes constrained subjects.
2. **Greedy** — candidates are tried by earliest day/time and suitable room.
3. **Conflict detection** — teacher, room, batch, capacity and availability checks.
4. **Backtracking** — recursive undo/retry when a future class cannot be placed.
5. **Searching** — linear search functions in C and live filtering in the UI.

## Share temporarily with Cloudflare Tunnel (optional)
First keep the website server running on port 8787. If `cloudflared` is installed:

```bash
cloudflared tunnel --url http://127.0.0.1:8787
```

Cloudflare will print a temporary `https://...trycloudflare.com` URL. The URL exists only while both processes are running.

## Static deployment
The website itself is static, so the root folder can be deployed to GitHub Pages, Netlify, Cloudflare Pages or another static host. The `c-engine` is for local/terminal DAA demonstration and is not executed by static hosting.

## Test checklist
- All 13 sidebar destinations render.
- Generator creates a complete timetable from sample constraints.
- Timetable has no teacher/room/batch collisions.
- Room capacities satisfy class size.
- Attendance warning appears below 75%.
- Search boxes filter entity tables.
- Reports, print buttons and settings work.
- C engine compiles with strict warnings and runs successfully.
