import { Controller, Get, Redirect, HttpException, HttpStatus, UseFilters } from '@nestjs/common'
import { AppService } from './app.service'
import { MyForbiddenException } from './forbidden.exception'

@Controller('app')
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get()
  getHello(): string {
    return this.appService.getHello()
  }

  @Get('redirect')
  @Redirect('http://nestjs.com', 301)
  getDocs() {}

  @Get('forbidden')
  getForbidden() {
    throw new MyForbiddenException()
  }
}
