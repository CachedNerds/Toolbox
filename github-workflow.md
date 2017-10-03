# Workflow Standards
There are many standard practices involving git and github when collaborating on a group project.  The standards defined below are **mandatory**, and anyone who works on this project are **required** to adhere to these standards.

## Git Standards
### Issues
The way that projects are often organized is the high level requirements of the project are broken down into individual tasks called **issues**.  These issues are then assigned to individual collaborators or a collaborator can pick up an issue.

### Branches
The collaborator will then create a branch from the master branch, this allows the collaborator to work on the task and make changes to the project without affecting the **master** branch.  If the issue you are working on is dependent on a branch that has not yet been merged into master, you will create a branch from master, merge the branch your issue is dependent on into the newly created branch, then implement your issue.  

The **name of the branch must follow the format**, issueN-identifier, where N is equal to the issue number on github and identifier is one or two words that briefly describe the issue. Example, issue15-build-system.  This allows people working on the project to be able to associate your branch with the issue its attempting to implement.

**Collaborators are never permitted to work directly with master ever.**

### Pull Request
Once a collaborator has completed their task they will push their branch to github and create a **pull request** from their branch to master.  Once the pull request has been created, it will require one of the administrators to review and approve the pull request.  At this point the reviewer can also leave comments in the pull request, stating changes that may need to be made or inquiring for the reason why the collaborator chose to do something.

If there are comments, address all comments on the same branch. After addressing the comments, update the comment stating that you have addressed the comment. Remember to push the modified code to the remote branch. This should update the original pull-request with the newly modified code.

Once the pull request has been approved by an administrator it is the collaborators responsibility to merge the pull request.
