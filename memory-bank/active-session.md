<!-- Memory Bank File: Active Session Tracker -->
<!-- Purpose: Track the current tutoring session state and immediate context -->
<!-- Update Frequency: During active tutoring sessions -->
<!-- Cross-references: Links to progress.md and tutoring-insights.md -->

# Active Session Context

**Session Date:** 2025-06-11 (ISO 8601 format: YYYY-MM-DD)
**Student Identifier:** alejiri

## Current Problem/Topic Focus:
- **Topic:** C++ Module 01 ex00 - BraiiiiiiinnnzzzZ (Zombie class implementation)
- **Specific Issue:** Successfully implemented basic zombie class with stack vs heap allocation patterns

## Current Code Under Review:
```cpp
// Completed cpp01/ex00 - Zombie class with proper memory management
// Zombie.hpp: Class declaration with constructor, destructor, announce method
// Zombie.cpp: Implementation with proper this-> usage
// main.cpp: Testing both newZombie (heap) and randomChump (stack)
// Makefile: C++ compilation with proper object file dependencies
```

## Student's Current Question/Blocker:
- Successfully resolved constructor/destructor implementation
- Discovered difference between manual destructor calls vs delete operator
- Understanding Makefile header dependencies and rebuild behavior
- Ready to progress to ex01 (zombieHorde with arrays)

## Key Points from Last Exchange:
- **Major breakthrough:** Understood that delete automatically calls destructor AND frees memory
- **Memory management insight:** Manual destructor calls clean object but leave memory allocated (memory leak)
- **Stack vs heap behavior:** Stack objects automatically destroyed, heap objects need explicit delete
- **Makefile discovery:** Header file changes trigger rebuilds, understanding dependency relationships
- **Compilation process:** Successfully resolved constructor syntax errors and access specifier issues

## Next Socratic Question/Guidance Plan:
- **Planned Question:** "Now that you understand single object allocation, what do you think happens when you need to create an array of zombies with new[]?"
- **Reasoning:** Bridge from single object management to array management for ex01
- **Backup Approaches:** Explore array allocation patterns and the relationship between new[]/delete[]

## Session Notes:
- Student showing excellent discovery-based learning through experimentation
- Strong grasp of memory ownership concepts emerging
- Good debugging skills with compiler errors
- Ready for more complex memory management scenarios
- Demonstrates understanding of object lifecycle and RAII principles

---
*This file should be updated after each exchange with the student and cleared when moving to a new problem/topic. Important insights should be moved to → progress.md or → tutoring-insights.md before clearing.*

**Cross-References:**
- **→ progress.md**: Transfer concept mastery evidence and learning milestones
- **→ tutoring-insights.md**: Move effective questioning strategies and successful techniques
- **← student-profile.md**: Reference learning preferences and known strengths when planning questions
- **← student-profile.md**: Reference learning preferences and known strengths when planning questions
