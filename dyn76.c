//#define DYN76_DEBUG
//#define DYN76_DEBUG_FKEEPER
/* File Keeper lists.  New entries are added at the top of the list
   Because both lists are treated a single shared resource they utilize
   the same lock, nfile_lock, to control CPU (thread) access */

static struct fkeeper *fkpr_head = NULL;  /* Open file status list */
/* File keeper list controls */
#define DO_FREE 1
#define NO_FREE 0
/* WARNING: This function MUST be called with nfile_lock already locked */
static void AddFKByID (U32 id, struct fkeeper *item, struct fkeeper **list)
    /* struct fkeeper * head = list; */
    item->id = id;
    item->next = *list;
    *list = item;
#ifdef DYN76_DEBUG_FKEEPER
    LOGMSG("DF18: AddFKByID added id=%d at %X with next item at %X to list head=%X at %X\n", 
           item->id, item, item->next, *list, list);
#endif 
static struct fkeeper * FindFK (U32 id, struct fkeeper **list)
#ifdef DYN76_DEBUG_FKEEPER
    LOGMSG("DF18: FindFK id=%d in list head at=%X\n", id, list);
#endif
    fk = *list;          /* Search the list */
#ifdef DYN76_DEBUG_FKEEPER
    LOGMSG("DF18: FindFK list head points to first entry at %X\n", fk);
#endif
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: FindFK id=%d (0x%X) is at: %X\n", fk->id, fk->id, fk);
#endif
static void RemoveFKByID (U32 id, struct fkeeper **list, int free_entry) 
#ifdef DYN76_DEBUG_FKEEPER
    LOGMSG("DF18: RemoveFKByID id %d from list head at=%X\n", id, list);
    fk = *list;
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: RemoveFKByID id=%d (0x%X) is at: %X\n", fk->id, fk->id, fk);
#endif
            {
            }
            {
                *list = fk->next;
            }
            if (free_entry)
            {
#ifdef DYN76_DEBUG_FKEEPER
                LOGMSG("DF18: RemoveFKByID freeing id=%d at: %X\n", fk->id, fk);
#endif
                free (fk);
            }
static int RemoveFKByName (char * filename) 
{
        {   /* Found the entry! */
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - orphan _close(%d)\n", fk->handle);
#endif
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - orphan _close result: %d\n", i);
#endif
            {
                i = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - orphan _close errno: %d\n", i);
#endif                
                i = -1 * i;
            }
            else 
            {
                {
                }
                {
                }
    int    res;                 /* I/O integer results */
#ifdef DYN76_DEBUG
    int    io_error = 0;        /* Saves the errno for log messages */
#endif
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: CFILE - looking for guest file descriptor %d\n", ghandle);
#endif
        fk = FindFK(ghandle, &fkpr_head);
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: CFILE - guest file descriptor %d found at %X\n", 
               ghandle, fk);
#endif
        {   /* Did not find the guest file descriptor.
               Treat it as if it were a bad host file handle */
            R15 = -1 * EBADF;
            set_reg(15,R15);
            return;
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: CFILE - _close(%d)\n", handle);
#endif
        res = _close (handle);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _close result: %d\n", res);
        R15 = res;
        {   RemoveFKByID (fk->id, &fkpr_head, DO_FREE);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _commit(%d)\n", handle);
        res =  _commit (handle);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _commit result: %d\n", res);
#endif
#else /* ifdef __MSVC__ */

#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - fsync(%d)\n", handle);
#endif
        res = fsync (handle);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - fsync result: %d \n", res);
#endif
#endif /* ifdef __MSVC__ */
        if (res != 0)
        {
            res = errno;
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - fsync/_commit errno: %d \n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {    
            R15 = res;
        }
        LOGMSG("DF18: CFILE - seek\n");
        get_reg(R3,3);  /* offset in bytes */
        get_reg(R4,4);  /* origin of the seek */
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _lseek(%d, %d, %d)\n", handle, (long)R3, (int)R4);
#endif
        res = _lseek (handle, (long)R3, (int)R4);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _lseek result: %d\n", res);
#endif        
        if (res == -1)
        {
            res = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - _lseek errno: %d\n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {    
            R15 = res;
        }

        R5 = restart_id++;        /* safely increment the id counter */
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: CFILE - adding restart fkeeper to rst_head list\n");
#endif
        AddFKByID(R5, rfk, &rst_head);

        rfk = FindFK(R5, &rst_head);
                    (&(rfk->oldname [rfk->data]), 
        LOGMSG("DF18: CFILE - rename\n");
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - rename(from='%s',to='%s')\n", 
                rfk->oldname, rfk->filename);
#endif
        res = rename (rfk->oldname, rfk->filename);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - rename result: %d\n", res);
#endif
        if (res != 0)
        {
            res = errno;
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - rename errno: %d\n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {
            R15 = res;
        }
        LOGMSG("DF18: CFILE - unlink\n");
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _unkink('%s')\n", rfk->filename);
#endif  
        res = _unlink (rfk->filename);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _unlink result: %d\n", res);
#endif
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - remove('%s')\n", rfk->filename);
        res = remove (rfk->filename);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - remove result: %d\n", res);
#endif
#endif
        if (res != 0)
        {
            res = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - remove/_unlink errno: %d\n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {
            R15 = res;
        }
        LOGMSG("DF18: CFILE - open\n");
        {
        }
        LOGMSG("DF18: CFILE - _open('%s', 0x%X, 0%o)\n", rfk->filename, i, R4);
        res = _open (rfk->filename, i, (mode_t)R4);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _open result: %d\n", res);
#endif        
        if (res != -1) 
            rfk->handle = res;  /* Save the host handle */

            /* Transfer the restart fkeeper to the open file fkeeper list */
#ifdef DYN76_DEBUG_FKEEPER
            LOGMSG("DF18: CFILE - removing  w/o freeing fkeeper from restart list rst_head\n");
#endif
            RemoveFKByID (rfk->id, &rst_head, NO_FREE);
            dolock(nfile_lock);
#ifdef DYN76_DEBUG_FKEEPER
            LOGMSG("DF18: CFILE - adding fkeeper to open file list with fkpr_head\n");
#endif
            AddFKByID(nfile_id++, rfk, &fkpr_head);
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - opened guest file descriptor %d, host handle: %d\n", 
                    rfk->id, rfk->handle);
#endif            
            unlock(nfile_lock);

            rfk = NULL;    

            res = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - _open errno: %X\n", res);
#endif
            R15 = -1 * res;
    {
        LOGMSG("DF18: CFILE - orphan close: '%s'\n", rfk->filename);
        LOGMSG("DF18: CFILE - read\n");
            if (rfk->data == 0) 
            { /* Need to fill our buffer with some data? */
            {   /* All done, we reached EOF (or an error occured) */
            }
            /* wstorec was designed to operate with storage-to-storage instructions.
               The instruction length field is always one less than the number of
               bytes involved in the instruction.  Hence the number of bytes to be
               moved to storage is decremented by 1 to conform with this behavior. */
            /* WARNING: This is where an interruption might occur.  An exception
               will "nullify" the storing operation.
               On restart, the read above will be bypassed and the entire sequence
               of bytes, upto 256, will be restored */
        LOGMSG("DF18: CFILE - write\n");
            /* wfetchc was designed to operate with storage-to-storage instructions.
               The instruction length field is always one less than the number of
               bytes involved in the instruction.  Hence the number of bytes to be
               retrieved from storage  is decremented by 1 to conform with this 
               behavior. */
            if (i > 255)
            {
            }
            /* WARNING: This is where interruption might occur.  The exception
               "nullifies" the fetch operation.
               On restart, the entire sequence of up to 256 bytes will be refetched
               from storage */
            i++;  /* Fix up number of bytes stored to actual count */
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - _write(%d, rfk->filename, %d)\n", handle, i);
#endif   
            res = _write (handle, rfk->filename, (size_t)i);
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - _write result: %d\n", res);
#endif   
            if (res < 0)
#ifdef DYN76_DEBUG
                io_error = errno;
                LOGMSG("DF18: CFILE - write errno: %d\n", io_error);
#endif 
            }

            /* Not an error, so 'res' is the number of bytes actually written */
            /* Update the address pointer and remaining bytes to write */
            R2 += res;
            set_reg(2,R2);
            R4 -= res;
            set_reg(4,R4);
            /* update the accumlated total */
            R15 += res;
        R5 = rfk->SaveArea;
    {
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: CFILE - removing and freeing restart fkeeper in rst_head list\n");
#endif
        /* Safely remove from the restart state */
        RemoveFKByID (rfk->id, &rst_head, DO_FREE);
    }