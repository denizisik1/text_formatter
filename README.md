### VimL

I changed my mind write it in rust, it it needs to be written anyway.

After adding it to the $PATH,

There has to be a vim shortcut of sorts:
Example:
```vim
nnoremap <leader>fft :!text_formatter expand('%:p:h'):edit<CR>
```

Abbreviation fft stands for (F)ile (F)ormat (T)ext. Should you have other formatters besides text.
Calling :e or :edit is required since vim will need to refresh the buffer to display changes.

Features to add:
Program should make sure that file it is checking has an empty line at the end.

Possibly adding libregex as a dependency(deeply burried) with its original name.
