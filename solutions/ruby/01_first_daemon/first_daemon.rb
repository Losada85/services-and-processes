#! /usr/bin/env ruby
# 
#first_daemon.rb

require 'tempfile'

puts 'About to daemonize'
Process.daemon
log=Tempfile.new('daemon.log')

loop do

log.put ("I'm a daemon doing daemon things")
log.flush
sleep 5
end
