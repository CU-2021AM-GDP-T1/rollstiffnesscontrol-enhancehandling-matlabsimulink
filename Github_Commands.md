# Github Comman Cheatsheet
***
## Git Merge Master into Branch
https://www.togaware.com/linux/survivor/Git_Merge_Master_into.html  
To re-synchronise a branch with updates that have been made to the main branch on the repository, first ensure the local main branch has been updated using a checkout and pull for the main branch. Then checkout the branch of interest and merge from the updated local main. We can then push the merges back to the remote repository's version of the branch. The commits are those that were committed by others to the remote repository's main branch.

```
git checkout main  
git pull  
git checkout validator  
git merge main  
git push  
```
Notice that we could skip the first two lines and change the merge to merge origin/main to also effect a merge from the remote main into the current branch. This will not then update the local copy of main.

```
git checkout validator  
git merge origin/main  
git push  
```

***
## Pull (or Merge) changes from (another) branch even with committed local changes
```
git reset #uncommit the local changes  
git stash #stash away uncomitted local changes  
git merge main #merge updates from main branch to the current child (selected) branch
git stash pop #pop back the uncomitted local changes
git commit -m "comments" #commit local changes
git push 
```
