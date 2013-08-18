watch(/.*\.cpp/) {
  system('zsh -c "source ~/.zshrc && g++-unit-tests"')
  system('echo aaa')
}
