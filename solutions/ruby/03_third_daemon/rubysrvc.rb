#rubysrvc.rb
require 'rubygems'
require 'win32/service'
include Win32

SERVICE_NAME ="RubySvc"
SERVICE_DISPLAYNAME = "A Ruby Service"
if ARGV[0] == "register"
   #Start the service.
   svc= Service.new
   svc.create_service do |s|
     s.service_name = SERVICE_NAME
     s.display_name = SERVICE_DISPLAYNAME
     s.binary_path_name = 'C:\InstantRails-1.3\ruby\bin\ruby' + File.expand_path($0) 
     s.dependencies = []
 end
end
  svc.close
  puts "Registered Service - " + SERVICE_DISPLAYNAME