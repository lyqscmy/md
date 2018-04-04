**git is a DAG**


[The beginner's guide to contributing to a GitHub project](https://akrabat.com/the-beginners-guide-to-contributing-to-a-github-project/#summary)

git pull upstream master && git push origin master
git push -u origin hotfix/readme-update

[git rebase](https://www.atlassian.com/git/tutorials/rewriting-history/git-rebase)

git reset --hard HEAD
git log --pretty=format:"%h %s" --graph

git branch iss53
git checkout iss53
git checkout -b iss53

```shell
git remote add origin https://github.com/user/repo.git
# Set a new remote
git remote -v
# Verify new remote
origin  https://github.com/user/repo.git (fetch)
origin  https://github.com/user/repo.git (push)
```