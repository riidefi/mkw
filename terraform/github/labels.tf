locals {
  # List of GitHub issue labels.
  # Changing label keys in this mapping causes removal of the label from all issues, so be careful.
  labels = {
    # Contribution type
    contrib_bug = {
      name        = "bug"
      color       = "d73a4a"
      description = "Bug report or fix"
    }
    contrib_decomp = {
      name        = "decomp"
      color       = "B07C62"
      description = "PRs that add decompiled code"
    }
    contrib_decompiler = {
      name        = "decompiler"
      color       = "F46AA5"
      description = "Improvements to decompiler tooling"
    }
    contrib_dependencies = {
      name        = "dependencies"
      color       = "0366d6"
      description = "PRs that update a dependency file"
    }
    contrib_devops = {
      name        = "devops"
      color       = "0052cc"
      description = "Changes to the build system and CI"
    }
    contrib_docs = {
      name        = "docs"
      color       = "0075ca"
      description = "Improvements to documentation"
    }
    contrib_splitting = {
      name        = "splitting"
      color       = "f9d0c4"
      description = "PRs that split assembly"
    }
    contrib_tracking = {
      name        = "tracking"
      color       = "FFFFFF"
      description = "Tracking issue for multiple decomp tasks"
    }
    # Meta
    meta_duplicate = {
      name        = "duplicate"
      color       = "cfd3d7"
      description = "This issue or PR already exists"
    }
    meta_good_first_issue = {
      name        = "good first issue"
      color       = "7057ff"
      description = "Good for newcomers"
    }
    meta_help_wanted = {
      name        = "help wanted"
      color       = "008672"
      description = "Extra attention is needed"
    }
    meta_invalid = {
      name        = "invalid"
      color       = "e4e669"
      description = "This doesn't seem right"
    }
    meta_question = {
      name        = "question"
      color       = "d876e3"
      description = "Further information is requested"
    }
    meta_wontfix = {
      name        = "wontfix"
      color       = "FFFFFF"
      description = "This will not be worked on"
    }
    # Priority
    priority_low = {
      name        = "p-low"
      color       = "fef2c0"
      description = ""
    }
    priority_medium = {
      name        = "p-medium"
      color       = "fbca04"
      description = ""
    }
    priority_high = {
      name        = "p-high"
      color       = "ff7619"
      description = ""
    }
    # Binaries
    area_dol = {
      name        = "a-dol"
      color       = "ED5A75"
      description = "main.dol image containing system libraries"
    }
    area_rel = {
      name        = "a-rel"
      color       = "006b75"
      description = "StaticR.rel binary containing game code"
    }
    # Library groups
    area_rvl = {
      name        = "a-rvl"
      color       = "ED5A75"
      description = "Area: Revolution system libraries (DOL)"
    }
    area_nw4r = {
      name        = "a-nw4r"
      color       = "7CC6A7"
      description = "Area: NW4R system libraries (DOL)"
    }
    area_egg = {
      name        = "a-egg"
      color       = "8FE87C"
      description = "Area: :egg: system library (DOL)"
    }
    area_net = {
      name        = "a-net"
      color       = "1E6E88"
      description = "Area: Gamespy and DWC networking (DOL)"
    }
    area_system = {
      name        = "a-system"
      color       = "d4c5f9"
      description = "Area: Game system libraries (REL)"
    }
    area_race = {
      name        = "a-race"
      color       = "E7FD60"
      description = "Area: Game RACE code (REL)"
    }
  }
}

resource "github_issue_label" "auto" {
  for_each = local.labels

  repository  = local.repo
  name        = each.value.name
  color       = each.value.color
  description = each.value.description
}
