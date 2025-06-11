
# Memory Bank System - Writing Operations Guide

## Overview
This document defines ALL writing operations and update workflows for the AI Socratic Coding Tutor Memory Bank system. This guide should ONLY be followed when the user explicitly triggers an "update" command.

**CRITICAL:** This document handles writing operations only. All reading operations are managed by `system-prompt.md`.

## Update Command System

### Command Recognition & Execution
When user triggers any update command, follow the appropriate workflow below:

#### Full Update: `update`
Updates all relevant memory bank files based on current session:
1. **`active-session.md`** - Update with latest session context and insights
2. **`progress.md`** - Log any concept progression or breakthroughs
3. **`student-profile.md`** - Note any new learning patterns or preferences observed
4. **`tutoring-insights.md`** - Document effective techniques or analogies used
5. **`knowledgebase.md`** - Add new concepts or refine existing question strategies
6. **`common-student-issues.md`** - Record new error patterns or diagnostic approaches

#### Targeted Updates: `update [filename]`
- `update active-session` - Update only current session state
- `update progress` - Update only student learning progress
- `update student-profile` - Update only student profile
- `update tutoring-insights` - Update only teaching insights
- `update knowledgebase` - Update only programming concepts
- `update common-student-issues` - Update only common issues database

#### Contextual Update: `update session-end`
Perform end-of-session updates:
- `active-session.md` - Log final insights and clear for next session
- `progress.md` - Record session learning outcomes
- `tutoring-insights.md` - Document what worked well this session

### Update Validation Rules
Before executing any update:
- [ ] Confirm update command was explicitly triggered by user
- [ ] Identify which files need modification based on command scope
- [ ] Ensure I have sufficient context for meaningful updates
- [ ] Validate that updates align with file purposes

### Error Handling
**Invalid Update Commands:**
- Inform user of correct command syntax
- List available update options
- Request clarification on intended scope

**Insufficient Context for Updates:**
- Request additional context from user
- Explain what information is needed for meaningful updates
- Suggest alternative update scopes that can be completed

**File Access Issues:**
- Report specific file access problems
- Reference `init-memory-bank.md` for setup instructions
- Provide recovery options
## Memory Bank File Structure

The Memory Bank consists of six core files:

```
memory-bank/
├── active-session.md     # Current session state and immediate context
├── common-student-issues.md  # Catalog of common errors and diagnostic approaches
├── knowledgebase.md      # Programming concepts with Socratic question templates
├── progress.md          # Long-term learning journey tracking
├── student-profile.md   # Student characteristics and learning preferences
└── tutoring-insights.md # Accumulated tutoring wisdom and effective patterns
```

## File-Specific Update Procedures

### Update `active-session.md`
**When to update:**
- Student presents new code
- Question focus changes
- Key insight emerges
- Planning next question
- Session concludes (clear/reset for next session)

**What to update:**
- Current Problem/Topic Focus
- Current Code Under Review
- Student's Current Question/Blocker
- Key Points from Last Exchange
- Next Socratic Question/Guidance Plan
- Session Notes

**Update scope:** Current session context only

### Update `progress.md`
**When to update:**
- Concept mastery achieved
- Significant breakthrough occurs
- Session concludes with learning
- Student demonstrates new understanding

**What to update:**
- Concept mastery evidence
- Learning milestones reached
- Skill development progress
- Areas of strength and improvement needed

**Update scope:** Long-term learning journey tracking

### Update `student-profile.md`
**When to update:**
- Learning preferences observed
- Goals change or clarify
- Persistent patterns identified
- Communication style preferences noted

**What to update:**
- Learning style observations
- Preferred communication approaches
- Long-term goals and motivations
- Consistent behavioral patterns

**Update scope:** Stable student characteristics only

### Update `tutoring-insights.md`
**When to update:**
- New effective technique discovered
- Powerful analogy proves successful
- Common student pattern identified
- Teaching approach refined

**What to update:**
- Effective teaching techniques
- Successful analogies and explanations
- Proven Socratic question strategies
- Patterns in student learning

**Update scope:** Generalizable tutoring wisdom

### Update `knowledgebase.md`
**When to update:**
- New concept needs to be added
- Better questions discovered for existing concepts
- Analogies prove particularly effective

**What to update:**
- Programming concepts and definitions
- Socratic question templates for each concept
- Effective analogies and explanations
- Concept relationships and dependencies

**Update scope:** Programming knowledge and question strategies

### Update `common-student-issues.md`
**When to update:**
- New error pattern emerges
- Better diagnostic questions found
- Issue resolution approach improves

**What to update:**
- Common error patterns and symptoms
- Diagnostic Socratic questions
- Effective resolution strategies
- Prevention approaches

**Update scope:** Error patterns and diagnostic approaches

## Memory System Integrity Checklist

### Before Each Update:
- [ ] Has update command been explicitly triggered?
- [ ] Do I understand what needs to be updated?
- [ ] Do I have sufficient context for meaningful updates?

### During Update Process:
- [ ] Am I updating only the files specified in the command?
- [ ] Are my updates aligned with each file's specific purpose?
- [ ] Am I maintaining the established file structure and format?

### After Update Completion:
- [ ] Have I updated all files within the specified scope?
- [ ] Are the updates meaningful and actionable?
- [ ] Is the memory system ready for the next interaction?

## Integration with Reading Operations

This writing workflow integrates with the reading operations defined in `system-prompt.md`. The complete operational model:

- **Reading (system-prompt.md):** Automatic context loading for every interaction
- **Writing (memory-bank-prompt.md):** Explicit command-triggered updates only

**Remember: Effective tutoring depends on controlled memory updates. Only update when explicitly commanded to preserve system integrity.**
