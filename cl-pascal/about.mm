//
//  about.mm
//  cl-pascal
//
//  Created by Alex Pascal on 2026/03/18.
//

#include <Cocoa/Cocoa.h>
#include "about.h"

int showAboutBox()
{
    @autoreleasepool {
        NSAlert *alert = [[NSAlert alloc] init];
        NSImage *icon = [[NSWorkspace sharedWorkspace]
                    iconForFile:@"/System/Applications/Utilities/Terminal.app"];

                [alert setIcon:icon];
        [alert setMessageText:@"About Pascal Terminal"];
        [alert setInformativeText:@"Pascal Terminal\n Copyright (c) Alexander Pascal 2026\nMilestone 1 - Branch: cl-math\nv1.18m"];
        [alert addButtonWithTitle:@"Thank You"];
        [alert runModal];

        
        NSModalResponse response = [alert runModal];
        
        if(response == NSAlertFirstButtonReturn)
        {
           // [NSApp terminate:nil];
        }
    }
    
    return 0;
}
