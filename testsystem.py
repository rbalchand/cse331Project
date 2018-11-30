import ptracer

def callback(syscall):
    print('{}({}) -> {}'.format(
        syscall.name,
        ', '.join(repr(arg.value) for arg in syscall.args),
        syscall.result.text))
    print('Traceback:')
    print(''.join(traceback.format_list(syscall.traceback)))

with ptracer.context(callback, filter=ptracer.SysCallPattern('open')):
	print("something opned")