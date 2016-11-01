# FreeBSD Ports

For functional ports, check the releases/tags named _-STABLE_ or _-RELEASE_ .

I am experiencing problems to download/fetch the distfiles/tags: they are all empty zip/tar.gz files. Until we have a solution, clone the repo and make the distfile: ```cd [repo_path] && tar --exclude .git -cjf $destdir/$distfile .``` 

## My Functional Ports

- Ardour 5.3 for FreeBSD and its (new) dependencies. For general notes, porting status, roadmap... see: *ARDOUR.md*
