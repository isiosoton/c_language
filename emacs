(setq  c-auto-newline  t)
(setq  compile-command  (concat"gcc -lm -Wall "))
(global-set-key  "\C-xz"  'next-error)
(global-set-key  "\C-xc"  'compile)
(global-set-key  "\C-h"  'delete-backward-char)

; Options Menu Settings
(setq make-backup-files nil)

; for cc-mode
;(add-hook 'c-mode-hook (lambda () (setq c-basic-offset 2)))

; for cc-mode
(add-hook 'c-mode-common-hook
          '(lambda ()
             (c-set-style "stroustrup")
             (setq c-basic-offset 2);
             (setq indent-tabs-mode nil)
	     ));
(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil :background "white" :foreground "black" :inverse-video nil :box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 120 :width normal :foundry "unknown" :family "DejaVu Sans")))))
